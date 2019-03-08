#include <stdio.h>

int multcnt = 0;

extern void multvec(int *x, int *y, int *z, int n)
{
    int i = 0;
    multcnt++;
    for (i = 0; i < n; i++)
    {
        z[i] = x[i] + y[i];
    }
}

extern int hellotwice(int num)
{
    printf("Hello World!");
    return num + num;
}