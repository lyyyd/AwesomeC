#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//void 函数的返回值和函数参数
void add(int a, int b)
{
    printf("%d\n", a + b);
    return;
}
void test(void)
{
    printf("hello world\n");
}

int main(void)
{
    add(10, 20);
    test();
    //void是空类型 不能定义变量
    //void a = NULL;//err

    int a = 10;
    //万能指针
    void* p = &a;
    //void** pp = &p;
    //通过void指针间接修改变量的值
    *(int*)p = 123;
    printf("%d\n", a);

    return EXIT_SUCCESS;
}
