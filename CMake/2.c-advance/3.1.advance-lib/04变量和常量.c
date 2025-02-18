#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//宏定义的常量 表达式 函数
#define MAX 100

//全局变量
int aa = 10;
//静态全局变量
static int b = 20;
int main()
{
    //在程序运行过程中其值可以改变的量 成为变量
    //局部变量
    auto int a = 10;
    //静态局部变量
    static int b = 20;

    printf("%p\n", &a);
    printf("%p\n", &b);
    return EXIT_SUCCESS;
}

//全局常量
const int c = 10;
int main0402()
{
    //常量 在程序运行过程中其值不能发生改变的量成为常量
    //const int a = 10;//只读变量 不安全 可以通过指针间接修改常量的值
    //int* p = &a;
    //*p = 123;
    //printf("%d\n", a);
    //printf("%d\n", MAX);

    //栈区溢出
    char str[1024 * 1024] = { 0 };

    return 0;
}
