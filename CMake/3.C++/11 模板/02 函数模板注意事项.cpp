#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1、自动类型推导的时候，必须确定正确T类型，才可以使用模板
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'a';

	mySwap(a, b);
	//mySwap(a, c);
}

template<typename T>
void func()
{
	cout << "func调用" << endl;
}

//2、模板不可以独立使用，必须确定出T类型，才可以使用
void test02()
{
	//func();
	func<int>();
}


int main()
{
	test02();


	system("pause");
	return 0;
}