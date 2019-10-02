#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	printf("Start...\n");
	fflush(NULL);

	int pid = fork();
	if(pid != 0){
		printf("pid is 0, in Parent Process, waitpid\n");
		signal(SIGCHLD, SIG_IGN);
		//sleep(10);
		execve("wait", NULL, NULL);
		wait();
		printf("Parent Process Exit Now!\n");
		sleep(10);
	}else{
		printf("In Child, sleep now\n");
		sleep(1);
		printf("Child Process Exit Now!\n");
	}
}
