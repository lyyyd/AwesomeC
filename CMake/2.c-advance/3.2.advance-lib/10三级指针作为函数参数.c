#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>



int main1001()
{
    //三级指针

    int a = 10;
    int b = 20;
    int* p = &a;
    int** p1 = &p;
    int*** p2 = &p1;

    //*p2 == p1 == &p;//二级指针的值
    //**p2 == *p1 == p == &a;//一级指针的值
    //***p2 == **p1 == *p == a;//变量的值
    ***p2 = 123;
    printf("%p\n", p);
    **p2 = &b;
    printf("%p\n", p);
    printf("%d\n", a);

    return EXIT_SUCCESS;
}

//三级指针作为函数参数 间接修改二级指针的值
void demo10(char*** p1)
{
    *p1 = (char**)malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++)
    {
        (*p1)[i] = (char*)malloc(100);
    }

    strcpy((*p1)[0], "你瞅啥");
    strcpy((*p1)[1], "(￣ε(#￣)☆╰╮o(￣皿￣///)");
    strcpy((*p1)[2], "再瞅一个试试");
}

int main1002()
{
    //输出特性 被调函数提供空间
    char** p = NULL;
    //三级指针作为函数参数 需要传递二级指针地址 地址传递
    demo10(&p);

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", p[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        free(p[i]);
    }
    free(p);
    return 0;
}
