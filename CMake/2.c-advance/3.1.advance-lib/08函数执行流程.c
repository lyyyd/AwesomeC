#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void plus(int a, int b)
{
    printf("%p\n", &a);
    printf("%p\n", &b);
    int sum = a + b;
    printf("%d\n", sum);
}

int main()
{
    int a = 10;
    int b = 20;
    plus(a, b);

    return EXIT_SUCCESS;
}


void demo1(int a)
{
    a = 100;
}
int main0802()
{
    int a = 10;
    //值传递  形参不能改变实参的值
    demo1(a);

    printf("%d\n", a);
    return 0;
}

void demo2(int* a)
{
    *a = 100;
}
int main0803()
{
    int a = 10;
    //地址传递  形参可以改变实参的值
    demo2(&a);
    printf("%d\n", a);
    return 0;
}

int main0804()
{
    int a = 10;
    int b = 20;
    int c = 30;

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
    return 0;
}