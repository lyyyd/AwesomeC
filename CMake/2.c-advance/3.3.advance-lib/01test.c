#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    //char a = -10;
    ////原码：1000 1010
    ////反码：1111 0101
    ////补码：1111 0110
    ////a>>1: 1111 1011-> 1111 1010 ->1000 0101 -5
    //char b = a >> 1;

    //printf("%d\n", b);

    char a = 20;

    //char b = a >> 98;//
    char b = a >> 2;

    printf("%d\n", b);

    return EXIT_SUCCESS;
}
