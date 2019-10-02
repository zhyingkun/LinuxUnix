#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _GNU_SOURCE
extern char **environ;
/* Or define _GNU_SOURCE to get it from <unistd.h> */

int main(int argc, char *argv[])
{
    char **ep;

    for (ep = environ; *ep != NULL; ep++)
        puts(*ep);

    // char *pwd = getenv("PWD");
    // printf("PWD: %p,    PWD: %s\n", pwd, pwd);
    // // *pwd = 'a';
    // char *newEnv = "zykTest=nice";
    // printf("newEnv: %p   newEnv: %s", newEnv, newEnv);
    // printf("putenv: %d\n", putenv(newEnv));
    // char *zykTest = getenv("zykTest");
    // printf("zykTest: %p,    zykTest: %s\n", zykTest, zykTest);

    // printf("argv: %p\n", argv);
    // printf("envp: %p\n", environ);

    // for (int i = 0; i < 40; i++)
    // {
    //     printf("&argv[%2d]:  %p   argv[%2d]:  %p  argv[%2d]: %s\n",
    //            i, &argv[i], i, argv[i], i, argv[i]);
    // }
    return 0;
}
