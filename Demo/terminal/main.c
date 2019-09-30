#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	
	if(isatty(0)){
		printf("stdin is tty\n");	
	}else{
		printf("stdin is not tty\n");
	}
	if(isatty(1)){
		printf("stdout is tty\n");	
	}else{
		printf("stdout is not tty\n");	
	}

	struct stat buf;
	fstat(0, &buf);
	printf("stdin: %d\n", major(buf.st_rdev));
	fstat(1, &buf);
	printf("stdout: %d\n", major(buf.st_rdev));
	fflush(NULL);
	close(0);
	close(1);
	close(2);
	for(;;);
	return 0;
}
