#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <memory.h>

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

void func()
{
	//栈解旋：从try开始起，到throw抛出异常对象前，栈上的所有数据都会被释放，释放的顺序与构造相反
	Person p1;
	Person p2;

	//智能指针
	auto_ptr<Person>p3(new Person);
	unique_ptr<Person>p4(new Person);  //memory头文件

	throw 1;
}

int main()
{
	try
	{
		func();
	}
	catch (int)
	{
		cout << "int类型异常捕获" << endl;
	}

	system("pause");
	return 0;
}