#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int myDivision(int a, int b)
{
	if (b == 0)
	{
		//return -1;  //C语言处理异常机制的缺陷是返回值可能是结果也可能是错误标识
		throw 1;
	}
	return a / b;
}

void test01()
{
	int a = 10;
	int b = 0;

	try
	{
		int ret = myDivision(a, b);
		cout << ret << endl;
	}
	catch (int)
	{
		cout << "int类型异常捕获" << endl;
	}

}

int main()
{

	test01();

	system("pause");
	return 0;
}