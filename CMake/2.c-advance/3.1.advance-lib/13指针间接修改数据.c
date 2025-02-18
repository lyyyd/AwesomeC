#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void test2(char* p)
{
    p = (char*)malloc(20);
    strcpy(p, "你瞅啥，瓜娃子\n");
    printf("%s", p);
}
void test3(char** p)
{
    *p = (char*)malloc(20);
    strcpy(*p, "你瞅啥，瓜娃子\n");
}
int main()
{
    char* p = NULL;
    //值传递
    //test2(p);
    //地址传递   二级指针间接修改一级指针的值   形参比实参高一个维度
    test3(&p);
    printf("%s", p);
    return EXIT_SUCCESS;
}
