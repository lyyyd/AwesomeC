#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//int类型数据交换
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//double 类型数据交换
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板实现交换功能
template<typename T> //T代表通用数据类型，告诉编译器在下面紧跟着的函数或者类中出现T不会报错
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//使用函数模板
void test01()
{
	//1、自动类型推导
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//2、显示指定类型
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double d1 = 1.1;
	double d2 = 2.2;
	mySwap<double>(d1, d2);
	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}