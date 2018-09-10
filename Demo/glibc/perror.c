#include <stdio.h>
#include <errno.h>
#include <string.h>

// extern int errno;

int main(int argc, char *argv[])
{
    errno = EBADF;
    perror("main");
    printf("Error: %s\n", strerror(errno));
    return 0;
}
