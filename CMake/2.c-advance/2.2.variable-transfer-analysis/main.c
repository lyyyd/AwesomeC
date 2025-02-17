#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void B()
{

}

void A()
{
    int a; // 只能在A B中使用
    B();
}


int main(){
    int a; // 在main A B 中都可以使用

    A();


//    test01();
    // test02();
    // test03();
    system("pause");
    return EXIT_SUCCESS;
}