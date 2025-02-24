#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//占位参数
//语法：在函数中只写参数的类型，不写参数名字
//占位参数也可以有默认参数，意义不大

void func(int a, int = 20)
{
}

int main()
{

	func(10);

	system("pause");
	return 0;
}