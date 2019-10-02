#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINE 16384

typedef struct fd_state {
	char buffer[MAX_LINE];
	size_t buffer_used;
	
	int writing;
	size_t n_written;
	size_t write_upto;
} fd_state;

fd_state* alloc_fd_state(void)
{
    struct fd_state *state = malloc(sizeof(struct fd_state));
    if (!state)
        return NULL;
    state->buffer_used = state->n_written = state->writing =
        state->write_upto = 0;
    return state;
}

void free_fd_state(fd_state* state)
{
    free(state);
}

void workerProcess(int sockfd)
{
	printf("pid:%d ppid:%d\n", getpid(), getppid());
	// all fd sets for select
	fd_set readfds, writefds, errorfds;
	// max fd
	int maxfd = 0;
	// all fd status
	fd_state *fdstate[FD_SETSIZE];
	for (int i = 0; i < FD_SETSIZE; i++)
	{
		fdstate[i] = NULL;
	}
	for (;;)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		FD_ZERO(&errorfds);
		// set the sockfd for read
		FD_SET(sockfd, &readfds);
		maxfd = sockfd;
		for (int i = 0; i < FD_SETSIZE; i++)
		{
			if (fdstate[i] != NULL)
			{
				if (i > maxfd)
					maxfd = i;
				FD_SET(i, &readfds);
				if (fdstate[i]->writing)
				{
					FD_SET(i, &writefds);
				}
			}
		}
		int selectret = select(maxfd, &readfds, &writefds, &errorfds, NULL);
		if (selectret < 0)
		{
			printf("error: select systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
			continue;
		}
		printf("pid:%d ppid:%d selectret:%d maxfd:%d\n", getpid(), getppid(), selectret, maxfd);
		if (FD_ISSET(sockfd, &rset))
		{ /* socket is readable */
			int acceptfd = accept(sockfd, NULL, NULL);
			printf("pid:%d ppid:%d acceptfd:%d accept...\n", getpid(), getppid(), acceptfd);
			if (acceptfd > 0)
			{
				// flags = fcntl(acceptfd, F_GETFL, 0);
				// fcntl(acceptfd, F_SETFL, flags | O_NONBLOCK); // non block socket
				fdarray[fdarraylen++] = acceptfd;
				FD_SET(acceptfd, &rset);
				maxfd = sockfd + 1;
				for (int i = 1; fdarray[i] != 0; i++)
				{
					if (maxfd < fdarray[i] + 1)
					{
						maxfd = fdarray[i] + 1;
					}
				}
			}
		}
		for (int i = 1; fdarray[i] != 0; i++)
		{
			int currentfd = fdarray[i];
			printf("currentfd:%d\n", currentfd);
			if (FD_ISSET(currentfd, &rset))
			{
				char buff[1024];
				// here is the non block socket
				errno = 0;
				int recvlen = recv(currentfd, buff, 1024, 0);
				if (recvlen > 0)
				{
					buff[recvlen] = '\0';
					printf("recvlen: %d\n", recvlen);
					printf("read from acceptfd: %s\n", buff);
				}
				else
				{
					printf("pid:%d recvlen:%d errno:%d strerror:%s\n", getpid(), recvlen, errno, strerror(errno));
					if (errno == EAGAIN)
						continue;
				}
				char buffer[1024];
				snprintf(buffer, 1024, "Hello %s", buff);
				int sendlen = send(currentfd, buffer, strlen(buffer), 0);
				printf("sendlen: %d\n", sendlen);
				close(currentfd);
				FD_CLR(currentfd, &rset);
				for (int i = 1; fdarray[i] != 0; i++)
				{
					if (currentfd == fdarray[i])
					{
						if (i == fdarraylen - 1)
						{
							fdarray[i] = 0;
						}
						else
						{
							fdarray[i] = fdarray[fdarraylen - 1];
							fdarray[fdarraylen - 1] = 0;
							fdarraylen--;
						}
						break;
					}
				}
				maxfd = sockfd + 1;
				for (int i = 1; fdarray[i] != 0; i++)
				{
					if (maxfd < fdarray[i] + 1)
					{
						maxfd = fdarray[i] + 1;
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	// the third para equals 0 means auto chose the right protocol for the second para
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) // if socket return -1, then it is an error, otherwise, it is the fd
	{
		fprintf(stderr, "error: socket systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
		return -1;
	}
	// set non block socket
	int flags = fcntl(sockfd, F_GETFL, 0);
	fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
	// bind the socket to a server address
	struct sockaddr_in srvaddr;
	memset(&srvaddr, 0, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	srvaddr.sin_port = htons(8888);
	int bindret = bind(sockfd, (const struct sockaddr *)&srvaddr, sizeof(srvaddr));
	if (bindret != 0) // bind return 0 if success
	{
		printf("error: bind systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
		close(sockfd);
		return -1;
	}
	// create a listen queue for the socket, the second param means the listen queue length
	int listenret = listen(sockfd, 16);
	if (listenret != 0) // listen return 0 if success
	{
		printf("error: listen systemcall return -1, errno:%d strerror:%s\n", errno, strerror(errno));
		close(sockfd);
		return -1;
	}
	// now start the server, create some worker process
	printf("Start...\n");
	printf("main pid:%d ppid:%d\n", getpid(), getppid());
	fflush(NULL);
	for (int i = 0; i < 4; i++)
	{
		int pid = fork();
		if (pid == 0) // fork return 0 if in child process
		{
			workerProcess(sockfd);
			exit(-1);
		}
		else
		{
			printf("In main process, process %d Created\n", pid);
		}
	}
	pause();
	return 0;
}
