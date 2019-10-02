#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) // if socket return -1, then it is an error, otherwise, it is the fd
    {
        printf("error: socket systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
        return -1;
    }
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("server ip: %s  server port: %d\n", "127.0.0.1", 8888);
    // servaddr.sin_addr.s_addr = inet_addr("192.168.31.244");
    // printf("server ip: %s  server port: %d\n", "192.168.31.244", 8888);
    int connectret = connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    if (connectret != 0)
    {
        printf("error: connect systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
        close(sockfd);
        return -1;
    }
    printf("sizeof zyk: %lu\n", sizeof("zyk"));
    int sendret = send(sockfd, "zyk", 4, 0);
    printf("sendret: %d\n", sendret);
    // use write systemcall to send msg is ok
    // int writeret = write(sockfd, "zyk", 4);
    // printf("writeret: %d\n", writeret);
    char buf[1024];
    int recvlen = recv(sockfd, buf, 1024, 0);
    buf[recvlen] = '\0';
    printf("recvlen: %d\n", recvlen);
    printf("receive from socket: %s\n", buf);
    // use read systemcall to receive the msg is ok
    // int readret = 0;
    // while ((readret = read(sockfd, buf, 1024)) > 0)
    // {
    //     buf[readret] = '\0';
    //     printf("readret: %d\n", readret);
    //     printf("read from socket: %s\n", buf);
    // }
    // printf("readret: %d errno:%d strerror:%s\n", readret, errno, strerror(errno));
    close(sockfd);
    return 0;
}
