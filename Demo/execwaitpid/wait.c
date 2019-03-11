#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("In wait exe, Before wait()\n");
	//wait();
	sleep(10);	
	printf("In wait exe, After wait()\n");
	return 0;
}
