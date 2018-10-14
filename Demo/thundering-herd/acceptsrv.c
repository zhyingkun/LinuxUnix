#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
// #include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    // the third para equals 0 means kernel will chose the right protocol for the second para automatically
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) // if socket return -1, then it is an error, otherwise, it is the fd
    {
        printf("error: socket systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
        return -1;
    }
    struct sockaddr_in srvaddr;
    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    // srvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // srvaddr.sin_addr.s_addr = inet_addr("192.168.31.244");
    srvaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    srvaddr.sin_port = htons(8888);
    int bindret = bind(sockfd, (const struct sockaddr *)&srvaddr, sizeof(srvaddr));
    if (bindret != 0) // bind return 0 if success
    {
        printf("error: bind systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
        close(sockfd);
        return -1;
    }
    int listenret = listen(sockfd, 10);
    if (listenret != 0) // listen return 0 if success
    {
        printf("error: listen systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
        close(sockfd);
        return -1;
    }
    printf("Start...\n");
    printf("main pid:%d ppid:%d\n", getpid(), getppid());
    printf("sockfd:%d bindret:%d listenret:%d\n", sockfd, bindret, listenret);
    fflush(NULL);
    for (int i = 0; i < 4; i++)
    {
        int pid = fork();
        if (pid == 0) // fork return 0 if in child process
        {
            printf("pid:%d ppid:%d\n", getpid(), getppid());
            for (;;)
            {
                int acceptfd = accept(sockfd, NULL, NULL);
                if (acceptfd < 0) // return the fd or error
                {
                    printf("error: accept systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
                    continue;
                }
                struct sockaddr_in sa;
                int len = sizeof(sa);
                int getpeerret = getpeername(acceptfd, (struct sockaddr *)&sa, (socklen_t *)&len);
                if (getpeerret == 0)
                {
                    printf("client ip: %s ", inet_ntoa(sa.sin_addr));
                    printf("client port: %d\n", ntohs(sa.sin_port));
                }
                else
                {
                    printf("getpeerret:%d error:%d strerror:%s\n", getpeerret, errno, strerror(errno));
                }
                printf("pid:%d ppid:%d acceptfd:%d\n", getpid(), getppid(), acceptfd);
                char buff[1024];
                int recvlen = recv(acceptfd, buff, sizeof(buff), 0);
                if (recvlen > 0)
                {
                    buff[recvlen] = '\0';
                    printf("recvlen: %d\n", recvlen);
                    printf("read from acceptfd: %s\n", buff);
                }
                else
                {
                    printf("recvlen: %d errno:%d strerror:%s\n", recvlen, errno, strerror(errno));
                }
                char buffer[1024];
                snprintf(buffer, 1024, "Hello %s", buff);
                int sendlen = send(acceptfd, buffer, strlen(buffer), 0);
                printf("sendlen: %d\n", sendlen);
                close(acceptfd);
            }
            break;
        }
    }
    wait(0);
    return 0;
}
