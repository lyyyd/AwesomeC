#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//自定义异常类
class myException
{
public:
	void printError()
	{
		cout << "我自己的异常捕获" << endl;
	}
};

void func()
{
	//throw 3.14;
	throw myException();
}

//1、异常必须有地方处理，如果没有处理异常，程序会调用terminate函数，使程序终止
//2、如果捕获的异常不想处理，想继续抛出，可以利用throw继续向上抛
//3、可以利用catch(...) 捕获其他类型异常
//4、可以自定义异常对象
void test01()
{
	try
	{
		func();
	}
	catch (int)
	{
		throw;
		cout << "int类型异常捕获" << endl;
	}
	catch (myException me)
	{
		me.printError();
	}
	catch (...)
	{
		cout << "其他类型异常捕获" << endl;
	}

}

int main()
{
	try
	{
		test01();
	}
	catch (int)
	{
		cout << "main函数中 int类型异常捕获" << endl;
	}


	system("pause");
	return 0;
}