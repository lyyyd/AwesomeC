#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	Person()
	{
		cout << "Person默认构造调用" << endl;
	}
	Person(int a)
	{
		cout << "Person有参构造调用" << endl;
	}
	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
};

void test01()
{
	int * pInt =  new int[10];  //在堆区创建了10个int大小的数组
	char* pChar = new char[10]; //在堆区创建了10个char大小的数组

	Person* pArray = new Person[10]; //在堆区创建了10个person大小的数组

	//堆区释放的时候 必须要加[]
	delete [] pArray;

	//提高 如果在栈上创建数组，可以没有默认构造函数
	Person arr[3] = { Person(10), Person(20),Person(30)};
}

int main()
{
	test01();


	system("pause");
	return 0;
}