#include <iostream>
using namespace std;
#include "game1.h"
#include "game2.h"

//1、命名空间用途：解决名称冲突
void test01()
{
	LOL::goAtk();
	KingGlory::goAtk();
}

//2、命名空间下可以存放变量、函数、结构体、类
namespace A
{
	int a = 0;
	void func() {}
	struct Person {};
	class Animal{};
}

//3、命名空间必须声明在全局作用域下
void test02()
{
	//namespace B {}  不能写到局部作用域下
}

//4、命名空间可以嵌套命名空间
namespace B
{
	int m_A = 10;
	namespace C
	{
		int m_A = 20;
	}
}
void test03()
{
	cout << "B空间下的m_A = " << B::m_A << endl;
	cout << "C空间下的m_A = " << B::C::m_A << endl;
}

//5、命名空间可以随时添加新成员
namespace B
{
	int m_B = 100;
}



void test04()
{
	cout << "B空间下的m_A = " << B::m_A << endl;
	cout << "B空间下的m_B = " << B::m_B << endl;
}


//6、命名空间可以是匿名的
namespace
{
	int m_C = 200;
	int m_D = 300;
}
void test05()
{
	cout << "m_C = " << m_C << endl;
	cout << "m_D = " << ::m_D << endl;
}

//7、命名空间可以起别名
namespace veryLongName
{
	int m_E = 1000;
}
void test06()
{
	//语法：namespace 别名 = 原名
	namespace VSN = veryLongName;
	cout << veryLongName::m_E << endl;
	cout << VSN::m_E << endl;
}

int main()
{
	test06();
	system("pause");
	return 0;
}
