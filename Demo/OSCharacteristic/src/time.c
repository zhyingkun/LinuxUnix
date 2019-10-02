#include <stdio.h>
#include <time.h>
#include <sys/time.h>

char* GetDateTime(){
	static char nowtime[20];
	time_t rawtime;
	struct tm* ltime;
	time(&rawtime);
	ltime = localtime(&rawtime);
	strftime(nowtime, 20, "%Y-%m-%d %H:%M:%S", ltime);
	return nowtime;
}

int main(int argc, char* argv){
	char* nowtime = GetDateTime();
	printf("NowTime: %s\n", nowtime);
	struct timeval utime;
	gettimeofday(&utime, NULL);
	printf("gettimeofday, sec:%d, usec:%d\n", utime.tv_sec, utime.tv_usec);
	return 0;
}
