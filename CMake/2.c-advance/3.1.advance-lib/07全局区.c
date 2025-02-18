#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//全局变量
int a = 10;
//全局常量
const int b = 10;
//未初始化全局变量
int c;
//静态全局变量
static int d = 10;
//未初始化静态全局变量
static e;
int main()
{
    //静态局部变量
    static int a = 10;
    //未初始化静态局部变量
    static int b;
    //字符串常量区  只读 不允许修改
    //char* p = "hello world";
    //char* p1 = "hello world";
    //char arr[] = "hello world";//栈区
    static char arr1[] = "hello world";//全局区
    arr1[2] = 'm';//ok
    //printf("%p\n", p);
    //printf("%p\n", p1);
    //*p = 'M';//err
    printf("%s\n", arr1);

    return EXIT_SUCCESS;
}
