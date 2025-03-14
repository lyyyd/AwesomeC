#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//普通函数
int myAdd1(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myAdd2(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	cout << myAdd1(a, c) << endl; //普通函数可以发生隐式类型转换

	//myAdd2(a, c); //错误，自动类型推导 因为推导不出正确的T类型 , 不会发生隐式类型转换

	cout << myAdd2<int>(a, c) << endl; //显示指定类型，可以发生隐式类型转换
}


int main()
{
	test01();


	system("pause");
	return 0;
}