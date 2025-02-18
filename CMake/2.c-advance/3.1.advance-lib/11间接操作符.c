#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int a = 10;
    int b = 20;
    //& 取地址运算符 引用运算符  升维度
    int* p = &a;
    int** pp = &p;
    //*p赋值
    //*p = 123;
    //*p取值
    //int b = *p;
    //一级指针间接修改变量的值
    //*p = 123;
    //二级指针间接修改一级指针的值
    //* 取值运算符 解引用运算符 降维度
    *pp = &b;
    **pp = 123;

    return EXIT_SUCCESS;
}
