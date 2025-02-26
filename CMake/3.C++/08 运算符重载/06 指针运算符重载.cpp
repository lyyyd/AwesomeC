#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		cout << "Person构造调用" << endl;
		this->m_Age = age;
	}

	void showAge()
	{
		cout << "age = " << this->m_Age << endl;
	}

	~Person()
	{
		cout << "Person析构调用" << endl;
	}

private:
	int m_Age;
};


//智能指针
class SmartPoint
{
public:
	SmartPoint(Person* person)
	{
		cout << "SmartPoint构造调用" << endl;
		m_Person = person;
	}

	//重载 ->
	Person* operator->()
	{
		return m_Person;
	}

	Person & operator*()
	{
		return *m_Person;
	}

	~SmartPoint()
	{
		if (m_Person != NULL)
		{
			cout << "SmartPoint析构调用" << endl;
			delete this->m_Person;
			this->m_Person = NULL;
		}
	}
private:
	Person* m_Person;
};


void test01()
{
	//Person * p = new Person(18);
	//p->showAge();
	//(*p).showAge();
	//delete p;

	SmartPoint sp(new Person(18));
	sp->showAge();    //本质是：sp->->showAge()  简化为 sp->showAge()
	(*sp).showAge();
}

int main()
{

	test01();

	system("pause");
	return 0;
}