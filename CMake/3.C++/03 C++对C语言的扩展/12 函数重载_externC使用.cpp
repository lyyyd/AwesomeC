#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "test.h"

//extern "C" void show();  //告诉编译器 show函数用c的方式去链接

int main()
{
    show();


    system("pause");
    return 0;
}