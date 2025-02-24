#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、全局变量检测增强
int a;
//int a = 10;  在C++下检测是重定义

//2、函数检测增强
//形参类型检测增强，形参和实参个数检测增强，若返回值不为void，要return相应的结果,函数返回值检测增强
int getRect(int w, int h)
{
	return w, h;
}

void test01()
{
	getRect(10, 10);
}

int main()
{



	system("pause");
	return 0;
}