#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class myException
{
public:
	myException()
	{
		cout << "myException的默认构造函数调用" << endl;
	}
	myException(const myException & e)
	{
		cout << "myException的拷贝构造函数调用" << endl;
	}
	~myException()
	{
		cout << "myException的析构函数调用" << endl;
	}
};

void func()
{
	throw new myException();
}

void test01()
{
	try
	{
		func();
	}
	//throw myException();   catch (myException e)   会调用拷贝构造 ，创建新的对象
	//throw myException();   catch (myException &e)  只有一份异常对象， 推荐使用
	//throw new myException();  catch (myException *e) 逻辑和引用是一样的，但是要加delete释放对象
	catch (myException *e)
	{
		cout << "我自己的异常捕获" << endl;
		delete e;
	}
}

int main()
{
	test01();


	system("pause");
	return 0;
}