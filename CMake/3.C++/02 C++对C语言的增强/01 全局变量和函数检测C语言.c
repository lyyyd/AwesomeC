#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、全局变量检测增强
int a;
int a = 10;

//2、函数检测增强
//C语言下函数可以不写返回值类型，形参可以不写数据类型，形参个数和实参可以不同，
//如果返回值类型不为void，也可以不return相应的结果
int getRect(w, h)
{
	//return w, h;
}

void test01()
{
	getRect(10, 10, 10);
}

int main()
{

	test01();

	system("pause");
	return EXIT_SUCCESS;
}