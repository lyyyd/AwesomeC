#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int a = 10;
    //定义指针变量指向变量地址
    int* p = &a;
    //通过指针间接修改变量的值
    *p = 123;
    printf("%d\n", a);
    //在32位操作系统下指针大小为4字节
    //在64位操作系统下指针大小为8字节
    printf("%d\n", sizeof(int*));
    return EXIT_SUCCESS;
}

int main0902()
{
    int a = 123456;
    char* p = &a;
    //如果指针p是char*类型 操作的内存空间大小为1字节
    *(int*)p = 123;
    printf("%d\n", a);
    return 0;
}
