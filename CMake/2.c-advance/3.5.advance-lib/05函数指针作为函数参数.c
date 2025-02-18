#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef void(*func)(int, int);
//函数声明
void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void dive(int a, int b);
//将函数指针类型作为函数参数
void calc(func f,int a, int b)
{
    //根据传递的参数不同 调用不同的函数
    f(a, b);
}
int main()
{
    //设计模式 -》工厂设计模式
    calc(add, 10, 20);
    calc(sub, 10, 20);
    return EXIT_SUCCESS;
}
