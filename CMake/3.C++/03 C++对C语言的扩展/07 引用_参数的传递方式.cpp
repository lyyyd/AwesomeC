#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、值传递
void mySwap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	mySwap1(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//2、地址传递
void mySwap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void test02()
{
	int a = 10;
	int b = 20;
	mySwap2(&a, &b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//3、引用传递
void mySwap3(int &a ,int &b) //int &a = a  int &b = b
{
	int temp = a;
	a = b;
	b = temp;
}
void test03()
{
	int a = 10;
	int b = 20;
	mySwap3(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


int main()
{
	test03();


	system("pause");
	return 0;
}