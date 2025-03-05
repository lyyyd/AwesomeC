#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	//纯虚函数
	//语法： virtual 返回值类型 函数名 （参数列表） = 0;
	//当类中有纯虚函数，此类称为抽象类
	virtual void func() = 0;
};

//子类必须重写父类中的纯虚函数，否则子类也是抽象类，毫无意义
class Son :public Base
{
public:
	void func()
	{
		cout << "func调用" << endl;
	}
};

int main()
{
	Base* base = NULL;
	//base = new Base; //抽象类 无法实例化对象
	base =  new Son;
	base->func();
	delete base;

	system("pause");
	return 0;
}