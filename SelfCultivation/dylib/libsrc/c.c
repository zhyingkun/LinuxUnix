#include <stdio.h>

extern int getValueFromC(int val)
{
	printf("In getValueFromC\n");
	return val*2+5;
}
