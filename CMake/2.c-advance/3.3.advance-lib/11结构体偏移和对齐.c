#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#pragma pack(4)

typedef struct Test
{
    int a;
    char b;
    short c;
    double d;
    char e[13];
    long f;
}test;

int main11()
{
    printf("%d\n", sizeof(test));

    return EXIT_SUCCESS;
}
