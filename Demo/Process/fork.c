#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

int globvar = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

void handleSIGCHLD(int what)
{
	printf("handleSIGCHLD: %d\n", what);
	// sleep(5);
}

int main(void)
{
	int var; /* automatic variable on the stack */
	pid_t pid;

	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		printf("write error\n");
	printf("before fork\n"); /* we don't flush stdout */
	printf("STDOUT_FILENO: %d  stdout: %d\n", STDOUT_FILENO, fileno(stdout));
	// fflush(stdout);
	struct sigaction newSigAction;
	newSigAction.__sigaction_u = (union __sigaction_u)handleSIGCHLD;
	newSigAction.sa_flags = 0;
	newSigAction.sa_mask = 0;
	newSigAction.sa_flags |= SA_RESTART;
	struct sigaction oldSigAction;
	if (sigaction(SIGCHLD, &newSigAction, &oldSigAction) != 0)
		printf("sigaction call error");
	if ((pid = fork()) < 0)
	{
		printf("fork error\n");
	}
	else if (pid == 0)
	{			   /* child */
		globvar++; /* modify variables */
		var++;
		printf("pid = %ld, glob = %d, var = %d  ...Child exit now!\n", (long)getpid(), globvar, var);
		sleep(3);
		return 21;
	}
	else
	{
		printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
		// printf("sleep return: %d\n", sleep(10)); /* parent */
		// perror("sleep");
		int statloc = 0;
		int n_pid = wait(&statloc);
		printf("n_pid: %d  errno: %d  statloc: %4x\n", n_pid, errno, statloc);
		perror("wait call");
		n_pid = wait(&statloc);
		printf("n_pid: %d  errno: %d  statloc: %4x\n", n_pid, errno, statloc);
		perror("wait call");
		printf("WIFEXITED(statloc): %d\n", WIFEXITED(statloc));
		printf("WEXITSTATUS(statloc): %d\n", WEXITSTATUS(statloc));

		printf("WIFSIGNALED(statloc): %d\n", WIFSIGNALED(statloc));
		printf("WTERMSIG(statloc): %d\n", WTERMSIG(statloc));

		printf("WCOREDUMP(statloc): %d\n", WCOREDUMP(statloc));

		printf("WIFSTOPPED(statloc): %d\n", WIFSTOPPED(statloc));
		printf("WSTOPSIG(statloc): %d\n", WSTOPSIG(statloc));
		sleep(1); /* parent */
	}

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
		   var);
	return 0;
}
