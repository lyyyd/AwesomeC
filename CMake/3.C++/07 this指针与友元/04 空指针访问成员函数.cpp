#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	void showClass()
	{
		cout << "this is Person class" << endl;
	}

	void showAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << "this age is " << m_Age << endl;
	}

	int m_Age = 0;
};

int main()
{
	Person* p = NULL;
	p->showClass();
	p->showAge();


	system("pause");
	return 0;
}