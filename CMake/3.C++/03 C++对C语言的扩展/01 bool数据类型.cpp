#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	bool flag = true;

	if (flag)
	{
		cout << "flag = true" << endl;
	}
	else
	{
		cout << "flag = false" << endl;
	}

	cout << sizeof(bool) << endl;
	cout << flag << endl; // false 本质是0  true 本质是1
}

int main()
{

	test01();

	system("pause");
	return 0;
}