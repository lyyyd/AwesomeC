#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//函数重载，函数名可以相同
//重载满足条件
//1、同一个作用域下
//2、函数名相同
//3、参数个数不同、或者类型不同、或者顺序不同

//struct Person
//{
//	void func() {};
//};

void func()
{
	cout << "func()调用" << endl;
}
void func(int a)
{
	cout << "func(int a)调用" << endl;
}
void func(double a)
{
	cout << "func(double a)调用" << endl;
}
void func(int a , double b)
{
	cout << "func(int a , double b)调用" << endl;
}
void func(double a,int b)
{
	cout << "func(double a,int b)调用" << endl;
}
//函数的返回值不能作为函数重载的条件
//int func(double a, int b)
//{
//	cout << "func(double a,int b)调用" << endl;
//	return 10;
//}

void test01()
{
	func(3.14,10);
}


int main()
{
	test01();


	system("pause");
	return 0;
}