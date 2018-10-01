#include <stdio.h>
#include <stdlib.h>

// Test for loop
int forloop()
{
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++)
    {
        sum += i + 1;
    }
    return sum;
}

// Test do while loop
int dowhileloop()
{
    int sum = 0;
    do
    {
        sum += 1;
    } while (sum < 3);
    return sum;
}

// Test while loop
int whileloop()
{
    int sum = 0;
    while (sum < 3)
    {
        sum += 1;
    }
    return sum;
}

// Test break and continue
int breakcontinue()
{
    int sum = 0;
    int i;
    for (i = 0; i < 10; i++)
    {
        if (i > 5)
        {
            sum += 1;
            continue;
        }
        if (i > 8)
        {
            sum += 3;
            break;
        }
        sum += 2;
    }
    return sum;
}

// Test if else goto
int ifelsegoto()
{
    int sum = 0;
start:
    if (sum < 10)
    {
        sum += 1;
        goto start;
    }
    else
    {
        sum += 2;
    }
    return sum;
}

// Test switch case default
int switchcasedefault()
{
    int sum = 0;
    int i;
    for (i = 0; i < 4; i++)
    {
        switch (sum)
        {
        case 0:
            sum += 1;
            break;
        case 1:
            sum += 2;
            break;
        case 2:
            sum += 5;
            break;
        default:
            sum += 6;
            break;
        }
    }
    return sum;
}

// Test function call
int functioncall(int a, char b, char *c, int d, int e, int f, int g)
{
    printf("char b: %c\n", b);
    printf("char*c: %s\n", c);
    return a + d + e + f + g;
}

// Varilable Scope
int GlobalVarInited = 10;
int GlobalVarNotInit;

// Global struct
struct StructType
{
    int index;
    char buf[3];
    char *name;
};
void displayStruct(struct StructType StructVar)
{
    printf("index: %d\n", StructVar.index);
    printf("buf: %c, %c, %c\n", StructVar.buf[0], StructVar.buf[1], StructVar.buf[2]);
    printf("*name: %s\n", StructVar.name);
}
struct StructType GlobalStructVar = {.index = 1, .buf = {'x', 'y', 'z'}, .name = "GlobalStructVar"};

int main()
{
    int LocalVar;
    char *StrPtr = "HelloWorld";
    char CharArray[] = "abcd";
    static int LocalStaticVar;
    char *NewPtr = (char *)malloc(10);
    struct StructType LocalStructVar = {.index = 2, .buf = {'u', 'v', 'w'}, .name = "LocalStructVar"};
    printf("GlobalVarInited: %d\n", GlobalVarInited);
    printf("GlobalVarNotInit: %d\n", GlobalVarNotInit);
    printf("LocalVar: %d\n", LocalVar);
    printf("LocalStaticVar: %d\n", LocalStaticVar);
    printf("StrPtr: %s\n", StrPtr);
    printf("CharArray: %s\n", CharArray);
    printf("NewPtr[0]: %c\n", NewPtr[0]);
    displayStruct(GlobalStructVar);
    displayStruct(LocalStructVar);
    int result = forloop();
    printf("forloop: %d\n", result);
    result = dowhileloop();
    printf("dowhileloop: %d\n", result);
    result = whileloop();
    printf("whileloop: %d\n", result);
    result = breakcontinue();
    printf("breakcontinue: %d\n", result);
    result = ifelsegoto();
    printf("ifelsegoto: %d\n", result);
    result = switchcasedefault();
    printf("switchcasedefault: %d\n", result);
    result = functioncall(1, 'b', "ccc", 2, 3, 4, 5);
    printf("functioncall: %d\n", result);

    return 0;
}
