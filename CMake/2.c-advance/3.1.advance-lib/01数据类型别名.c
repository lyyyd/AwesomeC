#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"tools.h"

//定义函数类型

//为结构体定义别名
typedef struct
{
    int id;
    char name[21];
    int age;
    char sex;
    char addr[51];
}student;

int main()
{
    ui a = 10;
    int64 b = 123456;
    student stu;

    stu.id = 1;

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", stu.id);

    return EXIT_SUCCESS;
}
