#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
// #include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <poll.h>

int main(int argc, char const *argv[])
{
    // the third para equals 0 means auto chose the right protocol for the second para
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    struct sockaddr_in srvaddr;
    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    srvaddr.sin_port = htons(8888);
    int bindret = bind(sockfd, (const struct sockaddr *)&srvaddr, sizeof(srvaddr));
    int listenret = listen(sockfd, 10);
    char buff[1024];
    printf("Start...\n");
    printf("main pid:%d ppid:%d sockfd:%d\n", getpid(), getppid(), sockfd);
    fflush(NULL);
    struct pollfd fdlist[10];
    fdlist[0].fd = sockfd;
    fdlist[0].events = POLL_IN | POLL_OUT;
    for (int i = 0; i < 4; i++)
    {
        int pid = fork();
        if (pid == 0) // fork return 0 if in child process
        {
            printf("pid:%d ppid:%d\n", getpid(), getppid());
            for (;;)
            {
                int pollret = poll(fdlist, 1, -1);
                printf("poll receive event: %d\n", fdlist[0].revents);
                printf("pid:%d ppid:%d selectret:%d poll\n", getpid(), getppid(), pollret);
                int acceptfd = accept(sockfd, NULL, NULL);
                printf("pid:%d ppid:%d acceptfd:%d accept...\n", getpid(), getppid(), acceptfd);
                if (acceptfd > 0)
                {
                    int readlen = read(acceptfd, buff, sizeof(buff));
                    // printf("%s", buff);
                    snprintf(buff, sizeof(buff), "HTTP/1.1 200 OK\n");
                    write(acceptfd, buff, strlen(buff));
                    snprintf(buff, sizeof(buff), "Content-Type:text/html\n\nHello World: %d", 12);
                    write(acceptfd, buff, strlen(buff));
                    close(acceptfd);
                }
            }
            break;
        }
    }
    wait(0);
    return 0;
}
