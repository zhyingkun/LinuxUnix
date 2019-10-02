#include <stdio.h>
#ifdef __linux
#include <pthread.h>
#else
#include <pthread/pthread.h>
#endif
#include <unistd.h>

void *printHello(void *argv)
{
    printf("Hello\n");
    printf("printHello pthread: %p\n", pthread_self());
    printf("printHello pthread_main_np: %d\n", pthread_main_np());
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t ptHello;
    printf("Main pthread: %p\n", pthread_self());
    printf("Main pthread_main_np: %d\n", pthread_main_np());
    pthread_create(&ptHello, NULL, printHello, NULL);
    printf("is equal: %d\n", pthread_equal(ptHello, pthread_self()));
    sleep(1);
    return 0;
}