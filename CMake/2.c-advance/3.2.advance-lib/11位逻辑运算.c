#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    //按位取反 单目运算符
    //0100 1110
    char a = 78;
    //0100 1110
    //1011 0001 补码
    //1011 0000 反码
    //1100 1111 -79
    char b = ~a;
    printf("%d\n", b);
    return EXIT_SUCCESS;
}

int main1102()
{
    //按位与 &  双目运算符
    //0100 1110
    char a = 78;
    //0101 1100
    char b = 92;

    //如果相同位 值都为1 结果为1
    //0100 1110
    //0101 1100
    //0100 1100  76

    char c = a&b;

    printf("%d\n", c);

    //0111 1111
    char a1 = 122;
    //0000 0000
    char a2 = 0;
    char a3 = 1;
    //结果为0
    printf("%d\n", a1&a2);
    //判断奇偶
    printf("%d\n", a1&a3);

    return 0;
}

int main1103()
{
    //位或运算 双目运算符 |
    //0100 1110
    char a = 78;
    //0101 1100
    char b = 92;
    //相同位 如果包含1 值为1
    //0100 1110
    //0101 1100
    //0101 1110  94


    printf("%d\n", a | b);
    return 0;
}

int main1104()
{
    //位异或运算 双目运算符
    //0100 1110
    char a = 78;
    //0101 1100
    char b = 92;

    //相同位  值相同为0 不同为1
    //0100 1110
    //0101 1100
    //0001 0010 //18

    printf("%d\n", a^b);
    return 0;

}

int main1005()
{
    //交换变量的值
    int a = 10;
    int b = 20;

    //1、临时变量
    //int temp = a;
    //a = b;
    //b = temp;
    //printf("%d\n", a);
    //printf("%d\n", b);

    //2、使用加减运算
    //a = a + b;//30
    //b = a - b;//10
    //a = a - b;//20
    //printf("%d\n", a);
    //printf("%d\n", b);

    //3、使用位异或运算
    a = a^b;
    b = a^b;
    a = a^b;
    //0000 1010
    //0001 0100
    //0001 1110 a第一次结果30

    //0001 1110
    //0001 0100
    //0000 1010 b计算结果为10

    //0001 1110
    //0000 1010
    //0001 0100 a计算结果为20

    printf("%d\n", a);
    printf("%d\n", b);
    return 0;

}