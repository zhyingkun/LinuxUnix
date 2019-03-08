#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
// #include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/event.h>
#include <fcntl.h>

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
    for (int i = 0; i < 4; i++)
    {
        int pid = fork();
        if (pid == 0) // fork return 0 if in child process
        {
            struct kevent event;  /* Event we want to monitor */
            struct kevent tevent; /* Event triggered */
            int kq = kqueue();
            EV_SET(&event, sockfd, EVFILT_READ | EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
            int keventret = kevent(kq, &event, 1, NULL, 0, NULL);
            printf("keventret: %d\n", keventret);
            if (keventret != 0)
            {
                return 1;
            }
            fflush(NULL);
            printf("pid:%d ppid:%d\n", getpid(), getppid());
            for (;;)
            {
                keventret = kevent(kq, NULL, 0, &tevent, 1, NULL);
                printf("pid:%d ppid:%d keventret:%d kqueue errno:%d\n", getpid(), getppid(), keventret, errno);
                // if (keventret != 0)
                // {
                //     return 1;
                // }
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
