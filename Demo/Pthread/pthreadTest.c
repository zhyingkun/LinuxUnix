#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* threadStart(void* ptr)
{
	printf("In thread\n");
	fflush(stdout);
	pause();
	return NULL;
}

int main(int argc, char* argv[])
{
	int a[1*1024*1024];
	a[1000*1000] = 12;
	for(int i=0; i<3; i++)
	{
		pthread_t tid;
		int ret = pthread_create(&tid, NULL, threadStart, NULL);
		printf("In Main Thread, pthread_create ret: %d\n", ret);
		fflush(stdout);
	}
	pause();
	return a[1000000];
}
