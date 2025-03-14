#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//throw() 代表不允许函数中抛出异常
//在vs下没有异常接口声明机制，可以在devC++ 或Qt或Linux下进行测试
void func()throw()
{
	throw 3.14;
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
	catch (...)
	{
		cout << "其他类型异常捕获" << endl;
	}


	system("pause");
	return 0;
}