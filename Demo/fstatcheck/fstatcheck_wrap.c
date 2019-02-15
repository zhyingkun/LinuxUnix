#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr, "usage: %s <fd>\n", argv[0]);
		exit(0);
	}
	dup2(STDIN_FILENO, atoi(argv[1]));
	execve("fstatcheck", argv, NULL);
	return 0;
}