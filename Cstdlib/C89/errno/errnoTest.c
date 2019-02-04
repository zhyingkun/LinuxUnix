#include <errno.h>

#include <stdio.h>
#include <math.h>

// Common Usage:
// if (somecall() == -1) {
// 	int errsv = errno;
// 	printf("somecall() failed\n");
// 	if (errsv == ...) { ... }
// }

int main(int argc, char* argv[]){
	errno = EACCES;
	perror("EACCES:");
	errno = EDOM;
	perror("EACCES:");
	errno = 0;
	double a = sqrt(-1.1);
	int errno1 = errno;
	perror("EACCES:");
	printf("errno1: %d\n", errno1);
	return 0;
}