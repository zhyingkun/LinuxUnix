#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	printf("Start...\n");
	int fd = 0;
	fd = open("123.txt", O_CREAT | O_RDWR, 0644);
	printf("fd: %d\n", fd);
	fd = open("456.txt", O_CREAT | O_RDWR, 0644);
	printf("fd: %d\n", fd);
	fd = open("789.txt", O_CREAT | O_RDWR, 0644);
	printf("fd: %d\n", fd);
	fd = open("abc.txt", O_CREAT | O_RDWR, 0644);
	printf("fd: %d\n", fd);
	fd = open("def.txt", O_CREAT | O_RDWR, 0644);
	printf("fd: %d\n", fd);
	char buffer[2048];
	scanf("%s", buffer);
	printf("%s\nEnd\n", buffer);
	return 2;
}
