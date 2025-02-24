#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、三目运算符
void test01()
{
	int a = 10;
	int b = 20;

	printf("%d\n", a > b ? a : b);
	//(a > b ? a : b) = 100; //C 语言下返回的是值
	*(a > b ? &a : &b) = 100; //模拟出C++的写法
	printf("b = %d\n", b);
}

//2、const
const int g_a = 100; //全局变量放在常量区 无法修改
void test02()
{
	//g_a = 200;  //直接修改失败
	//int* p = &g_a;
	//*p = 200;     //间接修改失败
	//printf("%d\n", *p);

	const int m_a = 100;  //放在栈区
	//m_a = 200;  //直接修改失败
	int* p = &m_a;
	*p = 200;
	printf("%d\n", *p);

	//C语言下const修饰的局部变量 称为伪常量
	//int arr[m_a]; //伪常量无法初始化数组
}

int main()
{
	test02();


	system("pause");
	return EXIT_SUCCESS;
}