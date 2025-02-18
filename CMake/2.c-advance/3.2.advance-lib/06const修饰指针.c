#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


typedef struct
{
    int id;
    char name[21];
    int age;
}student;

int main0601()
{
    //通过指针修改const定义的常量

    const int a = 10;//栈区
    int* p = &a;
    *p = 123;
    printf("%d\n", a);

    return EXIT_SUCCESS;
}

int main0602()
{
    int a = 10;
    int b = 20;
    //const 修饰指针类型
    const int* p = &a;
    //*p = 123;//err
    p = &b;//ok
}

int main0603()
{
    int a = 10;
    int b = 20;
    //const 修饰指针变量
    int* const p = &a;
    *p = 123;//ok
    //p = &b;//err
}

int main0604()
{
    int a = 10;
    int b = 20;
    const int* const p = &a;
    //*p = 123;//err
    //p = &b;//err

    int** pp = &p;
    //修改一级指针的值
    *pp = &b;//ok
    //修改变量的值
    **pp = 123;//ok
}

int main0605()
{
    student stu = { 1001,"粥粥",18 };
    student stu1 = { 1002,"法师",32 };

    //const student* p = &stu;
    //不能修改指针变量指向内存空间
    //p->id = 1002;//err
    //(*p).id = 1002;//err

    student* const p = &stu;
    p->id = 1002;//ok
    //p = &stu1;//err

}