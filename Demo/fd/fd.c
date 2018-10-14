#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void main(){

	int fd, fd1, fd2, fd3;
	fd = open("test.txt", O_WRONLY);
	printf("test : %d\n", fd);
//	write(1, (char)fd, 1);
	if(fd == -1)return;	

	fd1 = open("test1.txt", O_WRONLY);
	printf("test1 : %d\n", fd1);
	if(fd == -1)return;	
//	write(1, "Hello\n", 6);
	close(fd);
	close(fd1);

	fd2 = open("test2.txt", O_WRONLY);
	printf("test2 : %d\n", fd2);
	if(fd == -1)return;	
//	write(1, "Hello\n", 6);
	close(fd2);

	fd3 = open("error.txt", O_WRONLY);
	printf("error : %d\n", fd3);
	if(fd == -1)return;	
//	write(1, "Hello\n", 6);
	close(fd3);
	
	write(1, "Hello\n", 6);
	write(2, "Write to 2\n", 11);
	//fprintf((FILE *)2, "Error Out Put");

}
