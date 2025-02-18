#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main1201()
{
    //位图运算
    char a = 78;
    //0100 1110
    //0000 0010
    //0100 1110
    //打开位
    char b = a | 0x2;

    printf("%d\n", b);

    return EXIT_SUCCESS;
}


int main1202()
{
    //0100 1110
    char a = 92;
    //0100 1110
    //1011 0001
    //1111 1111 补码
    //1111 1110 反码
    //1000 0001 原码 -1
    //打开所有
    char b = a | ~a;

    printf("%d\n", b);
}

int main()
{
    //关闭所有为
    //0100 1110
    char a = 78;
    //0100 1110
    //1011 0001
    //0000 0000 结果为0
    char b = a & ~a;
    printf("%d\n", b);
    return 0;
}