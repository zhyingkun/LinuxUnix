#include <stdio.h>

extern int gDefInExe;
extern int gDefInB;
extern int gDefInA;
int gDefInA = 11;
static int sDefInA = 12;

extern int funcDefInExe();
extern int funcDefInB();

extern int funcDefInA()
{
	printf("This is in a.c\n");
	int all = gDefInExe + gDefInB + gDefInA + sDefInA;
	printf("all: %d\n", all);
	int ret = funcDefInExe();
	ret += funcDefInB();
	return ret;
}
