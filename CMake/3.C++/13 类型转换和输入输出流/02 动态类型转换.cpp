#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、内置数据类型之间不允许用 dynamic_cast
void test01()
{
	char a = 'a';

	//double d = dynamic_cast<double>(a);
}

//2、父子之间 转换
class Base { public: virtual void func() {} };
class Son:public Base{ public: virtual void func() {} };
class Other{};
void test02()
{
	Base* base = NULL;
	//将base转为Son* 向下类型转换 不安全
	//Son * s = dynamic_cast<Son*>(base);  //转换失败 因为不安全

	Son* son = NULL;
	//将son 转为 Base *  向上类型转换 安全
	Base * b = dynamic_cast<Base*>(son);  //转换成功，安全

	//将b 转为 Other *
	//dynamic_cast<Other*>(b);  //转换失败

	//如果发生多态，转换总是安全的
	//将b 转为 Son *
	Son* s = dynamic_cast<Son*>(b);
}

int main()
{



	system("pause");
	return 0;
}