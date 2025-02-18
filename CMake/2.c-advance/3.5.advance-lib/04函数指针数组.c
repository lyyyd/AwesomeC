#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef void(*func)(int, int);

void add(int a, int b)
{
    printf("%d\n", a + b);
}
void sub(int a, int b)
{
    printf("%d\n", a - b);
}
void mul(int a, int b)
{
    printf("%d\n", a * b);
}
void dive(int a, int b)
{
    printf("%d\n", a / b);
}

int main04()
{

    //定义函数指针数组
    func arr[4] = { add,sub,mul,dive };
    func* p = arr;//

    for (int i = 0; i < 4; i++)
    {
        //函数调用
        //arr[i](10, 20);
        (*(arr + i))(10, 20);
        //p[i](10, 20);
        (*p)(10, 20);
    }

    return EXIT_SUCCESS;
}
