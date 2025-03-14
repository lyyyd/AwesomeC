#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//普通函数
void myPrint(int a, int b)
{
	cout << "普通函数调用" << endl;
}

//函数模板
template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板调用" << endl;
}

/*
通过函数模板 产生的函数，称为模板函数
void myPrint(char a, char b)
{
	cout << "函数模板调用" << endl;
}
*/

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "函数模板调用(T a, T b, T c)" << endl;
}

void test01()
{
	//1、如果函数模板和普通函数都可以调用，优先选择普通函数
	int a = 10;
	int b = 20;
	myPrint(a, b);

	//2、可以通过空模板参数列表，强制调用函数模板
	//myPrint<>(a, b);

	//3、函数模板也可以发生函数重载
	myPrint(a, b,30);

	//4、如果函数模板可以产生更好的匹配，优先选择函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

int main()
{

	test01();

	system("pause");
	return 0;
}