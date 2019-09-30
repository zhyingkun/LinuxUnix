#include <stdio.h>
#include <stdarg.h>

int addAll(int a, ...)
{
	va_list argPtr;
	va_start(argPtr, a);
	int i,num,all=0;
	for(i=0; i<15; i++){
	num=va_arg(argPtr, int);
		all+=num;
		printf("num[%d]: %d addr: %p\n", i, num, argPtr);
	}
	va_end(argPtr);
	return all;
}

int main(int argc, char* argv[]){
	printf("all is %d\n", addAll(1,2,3,4,5,6,7,8,9));
	return 0;
}
