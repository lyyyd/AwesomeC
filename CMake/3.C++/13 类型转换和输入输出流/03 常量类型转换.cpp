#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//常量类型转换 const_cast
//对指针转换
void test01()
{
	int* p = NULL;
	//将p 转为 const int *

	const int * pp =  const_cast<const int*>(p);

	//将 pp 转为  int *
	int* ppp = const_cast<int*>(pp);
}

//对引用转换
void test02()
{
	int num = 10;
	int& ref = num;

	//将ref 转为 const int &
	const int & ref2 = const_cast<const int&>(ref);

	//将 ref2 转为 int &
	int & ref3 = const_cast<int&>(ref2);

	//不能对非指针或引用 使用 const_cast
	//const int a = 10;
	//int b = const_cast<int>(a);
}


int main()
{



	system("pause");
	return 0;
}