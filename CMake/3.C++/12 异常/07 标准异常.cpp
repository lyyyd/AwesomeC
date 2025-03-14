#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdexcept>  //系统标准异常头文件

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			throw out_of_range("年龄应该在 0 ~ 150之间");
		}
		this->m_Age = age;
	}
	int m_Age;
};

int main()
{
	try
	{
		Person p(1000);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}


	system("pause");
	return 0;
}