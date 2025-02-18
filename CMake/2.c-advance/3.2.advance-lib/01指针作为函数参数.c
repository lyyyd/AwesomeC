#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void test(char* str)
{
    strcpy(str, "性感法师在线讲课\n");
}


int main0101()
{
    //输入特性 主调函数提供空间 被调函数提供内容
    char str[100] = { 0 };
    test(str);

    printf("%s", str);

    return EXIT_SUCCESS;
}

void test1(char** p)
{
    //创建空间  通过二级指针间接修改一级指针的值
    *p = (char*)malloc(100);
    strcpy(*p, "传智播客，IT培训\n");
}

int main0102()
{
    //输出特性 被调函数提供空间 被调函数提供内容
    char* p = NULL;
    test1(&p);

    printf("%s", p);
    free(p);
    return 0;
}
