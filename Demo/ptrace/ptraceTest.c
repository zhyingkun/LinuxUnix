#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#ifdef __linux
#include <sys/reg.h>
#else
// #include <sys/user.h>
#endif

int main()
{
	pid_t child;
	long orig_eax, attach_ret = 0;
	child = fork();
	if (child == 0)
	{
		//ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		printf("Now Child Sleep: %d\n", getpid());
		sleep(1);
		printf("before execl\n");
		execl("/bin/ls", "ls", NULL);
		printf("after execl\n");
	}
	else
	{
		printf("Now Start Father Process: %d child: %d\n", getpid(), child);
		#ifdef __linux
		attach_ret = ptrace(PTRACE_ATTACH, child, NULL, NULL);
		#else
		attach_ret = ptrace(PT_ATTACH, child, NULL, NULL);
		#endif
		printf("Now Wait\n");
		wait(NULL);
		printf("Now Wait End\n");
		#ifdef __linux
		ptrace(PTRACE_CONT, child, NULL, NULL);
		#else
		ptrace(PT_CONTINUE, child, NULL, NULL);
		#endif
		wait(NULL);
		#ifdef __linux
		orig_eax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);
		#else
		// orig_eax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL);
		#endif
		printf("The child made a system call %ld  attach_ret: %ld\n", orig_eax, attach_ret);
		#ifdef __linux
		ptrace(PTRACE_CONT, child, NULL, NULL);
		#else
		ptrace(PT_CONTINUE, child, NULL, NULL);
		#endif
		wait(NULL);
		printf("father End\n");
	}
	return 0;
}
