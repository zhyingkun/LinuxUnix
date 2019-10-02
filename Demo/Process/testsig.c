#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sigchld_handler(int signo)
{
    printf("sigchld_handler\n");
    // sleep(3);
    return;
}

int main()
{
    int i;
    pid_t pid;
    pid_t cpid;
    // signal(SIGCHLD, sigchld_handler);
    struct sigaction newSigAction;
    newSigAction.__sigaction_u = (union __sigaction_u)sigchld_handler;
    newSigAction.sa_flags |= SA_RESTART;
    struct sigaction oldSigAction;
    if (sigaction(SIGCHLD, &newSigAction, &oldSigAction) != 0)
        printf("sigaction call error");
    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            sleep(2 + i);
            exit(0); // child exit.
        }
        else if (pid == -1)
        {
            perror("fork"); // fork failed.
            exit(-1);
        }
    }
    printf("before wait\n");
    // system("ps -ef | grep ttt");
    // while((cpid = waitpid(-1,NULL,0)!=-1)) {
    while ((cpid = wait(NULL)) != -1)
    {
        printf("wait pid is %d\n", cpid);
        continue;
    }
    printf("after wait\n");
    // system("ps -ef | grep ttt");
    errno = ECHILD;
    printf("ECHILD: %d\n", ECHILD);
    perror("ECHILD");
}
