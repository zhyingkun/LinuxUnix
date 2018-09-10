#include <stdio.h>

#ifdef __linux
#include <gnu/libc-version.h>
#endif

int main()
{

#ifdef __linux
    printf("__GLIBC__: %d  __GLIBC_MINOR__: %d\n", __GLIBC__, __GLIBC_MINOR__);
    printf("glibc version: %s\n", gnu_get_libc_version());
#endif

    printf("Hello World!\n");
    return 0;
}