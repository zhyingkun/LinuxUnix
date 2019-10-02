#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *val;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("%s environ-var\n", argv[0]);
        return 0;
    }

    val = getenv(argv[1]);
    printf("%s\n", (val != NULL) ? val : "No such variable");

    return 0;
}
