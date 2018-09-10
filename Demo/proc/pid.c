#include <stdio.h>
#include <unistd.h>
#include <errno.h>

// WINVER for windows
#ifdef __unix
#endif

#ifdef __linux
extern char etext, edata, end;

#define _GNU_SOURCE
extern char *program_invocation_name;
extern char *program_invocation_short_name;
#endif

int main(int argc, char const *argv[], char const *envp[])
{
    pid_t processID = getpid();
    pid_t parentID = getppid();
    printf("processID: %d  parentID: %d\n", processID, parentID);
#ifdef __linux
    printf("&etext: %p &edata: %p &end: %p\n", &etext, &edata, &end);
    printf("name: %s\n", program_invocation_name);
    printf("short_name: %s\n", program_invocation_short_name);
#endif
    // printf("sbrk: %p\n", sbrk(0));
    printf("argv: %p,  envp: %p\n", argv, envp);
    printf("argv-1: %p\n", argv - 1);
    printf("*(argv-1): %d\n", (int)*(argv - 1));
    printf("argv+1: %p\n", argv + 1);
    printf("argv+2: %p\n", argv + 2);
    printf("*(argv): %s\n", *(argv));
    printf("*(argv+1): %s\n", *(argv + 1));
    printf("*(argv+2): %s\n", *(argv + 2));
    printf("*(argv+3): %s\n", *(argv + 3));
    printf("*(argv+4): %s\n", *(argv + 4));

    return 0;
}
