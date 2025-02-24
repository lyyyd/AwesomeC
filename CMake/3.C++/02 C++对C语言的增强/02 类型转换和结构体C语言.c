#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、类型转换检测增强
void test01()
{
	int* p1 = NULL;
	char* p = p1;

	char* pp = malloc(4);
}

//2、结构体增强  C语言下结构体中必须至少有1个属性
struct Person {
	int age; //C语言下不可以有初始值
	//void showAge() {}   C语言下不可以有函数
};
void test02()
{
	struct Person p1; //C语言下创建结构体变量必须加关键字struct（没有用typedef）
}

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}