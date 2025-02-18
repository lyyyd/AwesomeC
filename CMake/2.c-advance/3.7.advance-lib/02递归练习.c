#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int sum = 1;

//分别打印千位 百位 十位 个位的数
void test1(int num)
{
    if (num == 0)
        return;
    int val = num / 10;
    test1(val);
    printf("%d\n", num % 10);
    return;
}

//计算一个数的阶乘
void test2(int num)
{
    if (num == 1)
        return;
    //sum *= num;//5*4*3*2
    test2(num - 1);
    sum *= num;//2*3*4*5
    return;
}
int main0201()
{
    int num = 8793;
    test1(num);
    return EXIT_SUCCESS;
}

int main0202()
{
    int num = 10;
    test2(num);
    printf("%d\n", sum);
    return 0;
}
