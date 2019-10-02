// process memory address
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define _GNU_SOURCE
extern char **environ;
/* Or define _GNU_SOURCE to get it from <unistd.h> */

#ifdef __linux
extern char etext, edata, end;
#endif

int main(int argc, char *argv[])
{
    // char **ep;

    // for (ep = environ; *ep != NULL; ep++)
    //     puts(*ep);
#ifdef __linux
    printf("&etext: %p &edata: %p &end: %p\n", &etext, &edata, &end);
#endif
    char *pwd = getenv("PWD");
    printf("PWD: %p,    PWD: %s\n", pwd, pwd);
    // *pwd = 'a';
    char *newEnv = "zykTest=nice";
    printf("newEnv: %p   newEnv: %s\n", newEnv, newEnv);
    printf("putenv: %d\n", putenv(newEnv));
    char testEnv[10000][40];
    for (int i = 0; i < 10000; i++)
    {
        sprintf(testEnv[i], "zykTest%d=nice%d", i, i);
        int ret = putenv(testEnv[i]);
        printf("i: %d   putenv: %d\n", i, ret);
        printf("&environ[%2d]:  %p   &environ[0]:  %p\n",
               i, &environ[i], &environ[0]);
    }
    printf("sizeof(environ): %ld", sizeof(environ));

    char *zykTest = getenv("zykTest");
    printf("zykTest: %p,    zykTest: %s\n", zykTest, zykTest);

    printf("argv: %p\n", argv);
    printf("envp: %p\n", environ);

    // char **ep;

    // for (ep = environ; *ep != NULL; ep++)
    //     puts(*ep);
    // for (int i = 0; environ[i] != NULL; i++)
    // {
    //     printf("&environ[%2d]:  %p   environ[%2d]:  %p  environ[%2d]: %s\n",
    //            i, &environ[i], i, environ[i], i, environ[i]);
    // }
    // unsetenv("SHELL");
    // for (int i = 0; environ[i] != NULL; i++)
    // {
    //     printf("&environ[%2d]:  %p   environ[%2d]:  %p  environ[%2d]: %s\n",
    //            i, &environ[i], i, environ[i], i, environ[i]);
    // }
    // for (int i = 0; i < 40; i++)
    // {
    //     printf("&argv[%2d]:  %p   argv[%2d]:  %p  argv[%2d]: %s\n",
    //            i, &argv[i], i, argv[i], i, argv[i]);
    // }
    return 0;
}
