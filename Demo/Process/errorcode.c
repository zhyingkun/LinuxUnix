#include <stdio.h>

__attribute((constructor)) void before_main()
{
    printf("%s\n", __FUNCTION__);
}
__attribute((destructor)) void after_main()
{
    printf("%s\n", __FUNCTION__);
}

int main(int argc, char *argv[])
{
    printf("Start Main \n");
    // printf("argv[2000]: %p\n", argv[2000]);
    int a;
    printf("sizeof a : %lu\n", sizeof(a));
    //This local var alloc will cause segament fault, the stack overflow
//    char array[8 * 1024 * 1024 - 1024 * 3 - 64 - 7];
//    printf("sizeof a : %lu\n", sizeof(array));
    return 0;
}
