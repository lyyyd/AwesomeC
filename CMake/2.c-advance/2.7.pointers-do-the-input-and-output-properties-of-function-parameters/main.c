#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


// 间接赋值的三大条件
// 1.两个变量 普通变量、指针变量  或者  实参 + 形参
// 2.建立关系
// 3.通过* 操作内存
void test01()
{
    int a = 10;
    int *p = NULL;

    p = &a;
    *p = 1000;

}

void changeValue(int *p)
{
    *p = 2000;
}

void test02()
{
    int a = 10;

    changeValue(&a);

    printf("%d\n", a);
    printf("%d\n", &a); // 根据a的地址可以操作吗
}

int main(){
    test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;
}
