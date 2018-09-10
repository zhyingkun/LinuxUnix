#include <stdio.h>

void func1()
{
position1:
    printf("func1\n");
}

void func2()
{
    int i = 2;
position2:
    printf("func2\n");
    if (i-- > 0)
        goto position2;
}

int main(int argc, char *argv[])
{
    func1();
    func2();

    return 0;
}