#include <stdio.h>

extern int gDefInExe;
extern int gDefInB;
int gDefInB = 21;
extern int gDefInA;
static int sDefInB = 22;

extern int funcDefInB()
{
	printf("This is in b.c\n");
	int all = gDefInExe + gDefInB + gDefInA + sDefInB;
	printf("all: %d\n", all);
	return 2;
}
