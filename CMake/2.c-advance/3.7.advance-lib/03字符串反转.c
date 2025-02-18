#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void reveser(char* str)
{
    if (*str == 0)
        return;
    reveser(str + 1);
    printf("%c", *str);
    return;
}
int main()
{

    char str[] = "hello world";
    reveser(str);
    return EXIT_SUCCESS;
}
