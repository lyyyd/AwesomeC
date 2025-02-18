#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//宏定义常量
//#define 常量名 值（注意 不能写= 和 ; ）
#define NUM 10

//宏定义表达式 需要将表达式使用括号括起来
#define RESULT (10 + 20)
//宏定义表达式 带参数
#define MAX(x,y) (x)>(y)?(x):(y)

//宏定义函数
#define len(str) strlen(str)

//将一个宏定义作为另外一个宏定义
#define VALUE(x) NUM>(x)?NUM:(x)

int main0201()
{
    //const int num = 10;
    int arr[NUM];
    return EXIT_SUCCESS;
}

//结束宏定义作用域
//#undef RESULT

int main0202()
{
    //printf("%d\n", RESULT);
    int a = RESULT*30;
    printf("%d\n", a);
    return 0;
}


int main0203()
{
    int value = MAX(10, 20);
    printf("%d\n", value);
    return 0;
}


int main0204()
{
    char str[] = "hello";

    printf("%d\n", len(str));
}