#include <stdio.h>
__attribute__((constructor(101))) void before_main()
{
	printf("%s\n",__FUNCTION__);
}
__attribute__((destructor(101))) void after_main()
{
	printf("%s\n",__FUNCTION__);
}

void printHello()
{
	printf("Hello\n");
}
void printCtors()
{
	printf("Ctors\n");
}
void printInitArray()
{
	printf("InitArray\n");
}
void printFiniArray()
{
	printf("FiniArray\n");
}

__attribute__((section(".ctors")))      void (*printPtr1)(void) = printCtors;
__attribute__((section(".init_array"))) void (*printPtr2)(void) = printInitArray;
__attribute__((section(".fini_array"))) void (*printPtr3)(void) = printFiniArray;
void main()
{
	atexit(printHello);
	printf("main\n");
//	_exit(1);
}
