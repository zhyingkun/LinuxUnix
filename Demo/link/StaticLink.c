#include <stdio.h>
#include <unistd.h>
#include "vector.h"

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];


int main(int argc, char const *argv[])
{
    addvec(x, y, z, 2);
	printf("pid: %d\n", getpid());
	int a;
	scanf("%d", &a);
    printf("z = [%d, %d] a=%d\n", z[0], z[1], a);
    return 0;
}
