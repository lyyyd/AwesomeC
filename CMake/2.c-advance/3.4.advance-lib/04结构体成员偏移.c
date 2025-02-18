#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct
{
    char a;//1
    int b;//4
    char c;//1
}test;

typedef struct
{
    char a;
    short b;
    int c;
    float d;
    double e;
}demo;
int main04()
{
    //test t = {'a',10,'b'};

    //printf("%d\n", sizeof(t));
    ////打印结构体成员地址
    //printf("%p\n", &t.a);
    //printf("%p\n", &t.c);
    //printf("%p\n", &t.b);


    printf("%d\n", sizeof(demo));
    return EXIT_SUCCESS;
}
