#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static pthread_t mainThread;

void* threadStart(void* ptr)
{
	sleep(2);
	//pthread_join(mainThread, NULL);
	printf("In thread\n");
	fflush(stdout);
	sleep(2);
	return NULL;
}

void runAtExit()
{
	printf("At Exit Now\n");
	fflush(NULL);
}

int main(int argc, char* argv[])
{
	atexit(runAtExit);
	mainThread = pthread_self();
	pthread_t tid;
	int ret = pthread_create(&tid, NULL, threadStart, NULL);
	printf("In Main Thread, pthread_create ret: %d\n", ret);
	fflush(stdout);
	//pthread_exit(NULL);
	pthread_join(tid, NULL);
	printf("Now the thread is exit");
	fflush(NULL);
	sleep(20);
	return 0;
}

