#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    clock_t start, end;
    start = clock();
    printf("Content-Type:text/html\n\n");
    printf("========\n");
    printf("%ld\n", start);
    printf("========\n");
    int sum = 0;
    for (int i = 0; i < 4000000; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (j < 50)
            {
                sum++;
            }
            else
            {
                sum--;
            }
            sum++;
        }
    }
    printf("%d\n", sum);
    printf("========\n");
    end = clock();
    printf("========\n");
    printf("%ld\n", end);
    printf("========\n");
    double cost = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f %d", cost, CLOCKS_PER_SEC);
    printf("========\n");
    return 0;
}
