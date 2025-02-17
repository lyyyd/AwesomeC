#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#define MYADD(x,y) x+y
#define MYADD(x,y) ((x)+(y)) // 使用空号

// 宏函数注意: 宏函数保证运算完整性
// 宏函数使用场景: 将频繁短小的函数封装为宏函数
// 优点: 空间换时间

int myAdd(int x, int y)
{
    return x + y;
}

void test01()
{
    int a = 10;
    int b = 20;

    printf("a + b = %d\n", MYADD(a,b));
    printf("a + b = %d\n", MYADD(a,b) * 20); // 10 + 20 * 20
}

int main(){
    test01();
    // test02();
    // test03();
    system("pause");
    return EXIT_SUCCESS;
}