#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//构造函数和析构函数
class Person
{
public:

	//构造函数
	//1、没有返回值  不写void
	//2、函数名 与 类名相同
	//3、可以有参数，可以函数重载
	//由编译器自动调用一次，无需手动调用
	Person()
	{
		cout << "Person的构造函数调用" << endl;
	}

	//析构函数
	//1、没有返回值 不写void
	//2、函数名 与 类名相同 前面加 ~
	//3、不可以有参数 不可以函数重载
	//析构函数编译器自动调用一次，无需手动调用
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

};

void test01()
{
	Person p1;
}

int main()
{

	test01();


	system("pause");
	return 0;
}