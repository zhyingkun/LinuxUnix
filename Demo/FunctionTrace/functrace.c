#include <stdio.h>

int printHello(int a, int b, int c)
{
	//printf("%d, %d, %d\n", a, b, c);
	char aa='A';
	return a+b+c;
}
void realPrint(long* addr)
{
	long la=-1;
	long* ptr;
	for(ptr = addr; ptr>=&la; ptr--)
	{
		printf("addr: %p\t\tdata: %p\t\tHigh4: %d\n", ptr, *ptr, *(((int*)ptr)+1));
	}
	long* ptrArgc = addr-1;
	printf("*(addr+1) ==> %d\n", *(int*)(*ptrArgc));
	//printHello(12, 12, 12);
}
void printStackAddr(long* addr)
{
	int a=12;
	realPrint(addr);
}
void printStackAddr2(long* addr)
{
	long a=23;
	printStackAddr(addr);
}
void printStackAddr3(long* addr)
{
	char b='A';
	printStackAddr2(addr);
}
int main(int argc, const char* argv[], const char* envp[])
{
	long ga=0;
	printStackAddr3(&ga);
	printf("argc: %d, argv: %p, envp: %p\n", argc, argv, envp);
	//const char* name = argv+2;
	printf("argv[0]: %p\n", argv[0]);
	printf("argv[1]: %ld\n", (long)argv[1]);
	printf("argv[0]: %s\n", argv[0]);
	return 0;
}
