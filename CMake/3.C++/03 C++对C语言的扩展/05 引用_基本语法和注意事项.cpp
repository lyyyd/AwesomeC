#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//引用
//用途：给变量起别名
//语法：数据类型 & 别名 = 原名
void test01()
{
	int a = 10;
	int& b = a;

	b = 20;

	cout << a << endl;
	cout << b << endl;
}

//注意事项1：引用必须初始化
void test02()
{
	//int& b; //错误，必须初始化
}

//注意事项2：引用一旦初始化后，就不可以引其他变量
void test03()
{
	int a = 10;
	int& b = a;
	int c = 20;
	b = c; //并不是修改b引用的指向，而是给b赋值
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//注意事项3：引用必须引可修改的内存空间
void test04()
{
	//int& b = 10; //错误
}

//注意事项4：不要返回局部变量的引用
int& func()
{
	int a = 10;
	return a;
}
void test05()
{
	int& ref = func();
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;
}

//注意事项5：当函数的返回值是引用，函数的调用可以作为左值
int& func2()
{
	static int a = 10;
	return a;
}

void test06()
{
	int& ref = func2();
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;

	func2() = 200;

	cout << ref << endl;
}

int main()
{
	test06();


	system("pause");
	return 0;
}