#include "stdio.h"
#include "unistd.h"
 
int main(int argc, char const *argv[])
{
	char buf[10]={0};
	read(STDIN_FILENO,buf, 5);
	write(STDOUT_FILENO,buf, 5);
	return 0;
}
