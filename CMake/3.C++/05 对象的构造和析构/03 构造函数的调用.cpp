#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int a)
	{
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(int a ,int b)
	{
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(const Person & p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

void test01()
{
	//1、括号法
	Person p1(10);
	Person p2(p1);
	//注意事项1：不要理由括号法 调用默认构造函数
	//Person p3(); //编译器会认为这个是函数的声明，而不是实例化对象
}

void test02()
{
	//2、显示法
	Person p1 = Person(); //默认构造
	Person p2 = Person(10); //有参构造
	Person p3 = Person(p1); //拷贝构造

	Person(10); //匿名对象  特点：当前行执行完，立即释放
	cout << "aaaa" << endl;
	//注意事项2：不要理由拷贝构造函数 初始化匿名对象
	//Person(p4); //认为对象的创建，并调用默认构造函数，而不是匿名对象
}

void test03()
{
	//隐式法  隐式转换法  写法简单 可读性低
	//Person p1 = 10;  // Person p1 = Person(10)
	//Person p2 = p1;  // Person p2 = Person(p1)

	//注意事项3： 隐式法 只适用于单参数
	Person p3(10, 20);
	Person p4 = Person(10, 20);
	Person p5 = (10, 20);
}

int main()
{

	test03();

	system("pause");
	return 0;
}