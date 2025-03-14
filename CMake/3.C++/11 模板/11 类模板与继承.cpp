#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、父类为类模板
template<class T>
class Base
{
public:
	int m_A;
};

class Son :public Base<int>  //当父类是类模板时，子类必须确定T的类型，否则无法分配内存
{

};

//2、父子类 均为类模板
template<class T>
class Base2
{
public:
	int m_A;
};

template<class T ,class T2>
class Son2 :public Base2<T>
{
public:
	Son2()
	{
		cout << "T的类型：" << typeid(T).name() << endl;
		cout << "T2的类型：" << typeid(T2).name() << endl;
	}
	T2 m_B;
};

void test01()
{
	Son2<string, int>s;
}

int main()
{

	test01();

	system("pause");
	return 0;
}