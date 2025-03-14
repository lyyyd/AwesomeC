#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、静态类型转换
//内置数据类型之间转换
void test01()
{
	char a = 'a';
	//语法： static_cast<目标类型>(待转换变量/对象)
	double d = static_cast<double>(a);

	cout << d << endl;
}

//2、父子间转换  指针或引用
class Base{};
class Son:public Base{};
class Other{};

void test02()
{
	Base* base = NULL;
	//将base 转为 Son *  父转子 向下类型转换 不安全
	Son* s = static_cast<Son*>(base);

	Son* son = NULL;
	//将son 转为 Base *   子转父 向上类型转换 安全
	Base* b = static_cast<Base*>(son);

	//将b 转为 Other *
	//Other * o = static_cast<Other*>(b);  //error 不是继承关系 转换无效
}

int main()
{
	test01();


	system("pause");
	return 0;
}