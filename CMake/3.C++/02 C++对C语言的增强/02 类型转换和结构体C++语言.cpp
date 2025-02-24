#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、类型转换检测增强
// 如果想不同类型指针之间赋值，可以利用强制类型转换
void test01()
{
	int* p1 = NULL;
	char* p = (char *)p1;

	char* pp = (char *)malloc(4);
}

//2、结构体增强  C++语言下结构体中可以没有任何属性
struct Person {
	//int age = 18; //C++语言下可以有初始值
	//void showAge() { cout << age << endl; }   //C++语言下可以有函数
};
void test02()
{
	//Person p1; //C++语言下创建结构体变量可以不加关键字struct
	//p1.showAge();
}

int main()
{
	test02();


	system("pause");
	return 0;
}