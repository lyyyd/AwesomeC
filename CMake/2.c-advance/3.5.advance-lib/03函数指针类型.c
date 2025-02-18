#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//返回值类型 函数参数个数 函数类型都相同 表示是一个函数类型
//定义函数类型
typedef void (func)(int, int);
typedef void (*type)(int, int);

void add1(int a, int b)
{
    printf("%d\n", a + b);
    return;
}

int sub1(int a, int b,int c)
{
    printf("%d\n", a - b);
    return a-b;
}

int main0301()
{

    int a = 10;
    int b = 20;
    //调用函数
    add(a, b);
    //函数名是函数代码区地址常量
    printf("%p\n", add);
    return EXIT_SUCCESS;
}

int main0302()
{
    int a = 10;
    int b = 20;
    //函数数据类型* 函数变量=函数地址
    func* f = add1;
    //add(a, b);
    f(a, b);

    printf("%p\n", f);
    printf("%p\n", add1);
    return 0;
}

int main0303()
{
    //函数类型指针
    type t = add1;
    t(10, 20);
    t = sub1;//err  函数类型不同 不能赋值
    t(10, 20);
    return 0;
}

int main0304()
{
    type t = add1;
    type** tt = &t;
    //printf("%p\n", add);
    //printf("%p\n", &add);
    //(*t)(10, 20);//err
    return 0;
}