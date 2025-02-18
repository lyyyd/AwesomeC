#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//设定对齐方式
//优点 更合理利用内存
//缺点 CPU算力下降
//#pragma pack(1)
//#pragma pack(2)
//#pragma pack(16)


typedef struct
{
    char a;//2 1 - 1
    short b;//2
    int c;//2 2
    float d;// 2 2
    double e;//2 2 2 2
}demo;
int main0501()
{

    printf("%d\n", sizeof(demo));
    return EXIT_SUCCESS;
}

typedef struct
{
    char a;
    int c:1;//结构体成员定义时 可以约束 字节大小
    int b;
}test;

int main0502()
{
    printf("%d\n", sizeof(test));
    return 0;
}