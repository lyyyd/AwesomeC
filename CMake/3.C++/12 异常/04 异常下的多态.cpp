#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常的基类
class BaseException
{
public:
	virtual void printError() {}
};

//空指针异常类
class NullPointer :public BaseException
{
public:
	virtual void printError() { cout << "空指针异常" << endl; }
};

//越界异常类
class OutOfRange :public BaseException
{
public:
	virtual void printError() { cout << "越界异常" << endl; }
};

void func()
{
	//throw NullPointer();
	throw OutOfRange();
}

void test01()
{
	try
	{
		func();
	}
	catch( BaseException & e)
	{
		e.printError();
	}
}
int main()
{

	test01();

	system("pause");
	return 0;
}