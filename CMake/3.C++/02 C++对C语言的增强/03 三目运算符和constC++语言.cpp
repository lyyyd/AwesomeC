#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、三目运算符
void test01()
{
	int a = 10;
	int b = 20;

	printf("%d\n", a > b ? a : b);
	(a > b ? a : b) = 100; //C++ 语言下返回的是变量
	cout << b << endl;
}

//2、const
const int g_a = 100;  //放在常量区 无法修改

void test02()
{
	//g_a = 200;  //直接修改失败
	//int* p = (int *) & g_a;
	//*p = 200;   //间接修改失败
	//cout << *p << endl;

	const int m_a = 100;
	//m_a = 200;  //直接修改失败
	int* p = (int*) & m_a;  // 将m_a放在符号表，如果对数据取地址，此时会产生临时局部变量，让指针指向局部变量
	*p = 200;
	cout << *p << endl;
	cout << m_a << endl;

	int arr[m_a];
}

int main()
{
	test02();


	system("pause");
	return 0;
}