#include <stdio.h>

int main(int argc, char* argv[])
{
	perror("Test perror"); // for syscalls, useful with errno
	return 0;
}
