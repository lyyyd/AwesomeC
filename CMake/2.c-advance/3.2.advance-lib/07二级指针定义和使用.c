#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main0701()
{
    int a = 10;
    //数据类型* 指针变量=&变量
    int* p = &a;
    //数据类型** 指针变量=&指针变量
    int** p1 = &p;

    //一级指针的值
    //printf("%p\n", *p1);
    //printf("%p\n", p);
    //printf("%p\n", &a);
    //变量的值
    //printf("%d\n", **p1);
    //printf("%d\n", *p);
    //printf("%d\n", a);


    **p1 = 123;
    printf("%d\n", a);
    return EXIT_SUCCESS;
}

int main0702()
{
    //指针大小
    int a = 10;
    int* p = &a;
    int** p1 = &p;

    printf("%d\n", sizeof(p1));
    printf("%d\n", sizeof(int***));
    printf("%d\n", sizeof(double **));
    printf("%d\n", sizeof(long **));
}


int main0703()
{
    int a = 10;
    int b = 20;
    int* p = &a;
    int* p1 = &p;//err

    printf("%p\n", p);
    //改变p的值
    //*p1 = &b;
    //改变变量a的值
    **(int**)p1 = 123;
    printf("%p\n", p);
    printf("%d\n", a);
    return 0;
}