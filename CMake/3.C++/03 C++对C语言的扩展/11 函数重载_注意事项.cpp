#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、函数重载 普通引用和常量引用可以共存
void func(int &a)
{
	cout << "func(int &a) 的调用" << endl;
}
void func(const int& a)
{
	cout << "func(const int& a) 的调用" << endl;
}
//注意：当出现引用的版本，就不要在同时出现不加引用的重载了，因为调用会产生二义性
//void func(int  a)
//{
//	cout << "func(const int& a) 的调用" << endl;
//}
void test01()
{
	func(10); //调用加const的引用
	int a = 10;
	func(a);
}

//2、函数重载的时候，尽量不要使用默认参数，可能会产生二义性
void func2(int a)
{
	cout << "func2(int a)调用" << endl;
}
void func2(int a, int b = 10)
{
	cout << "func2(int a,int b = 10)调用" << endl;
}
void test02()
{
	//func2(10, 20);
	//func2(10);  两个都可以调用，产生二义性
}

int main()
{

	test02();

	system("pause");
	return 0;
}