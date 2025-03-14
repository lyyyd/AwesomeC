#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//案例1 ： 用户输入数字或字符串，我们进行判断并输出相应的结果
int main()
{
	cout << "请输入一个数字或字符串" << endl;

	char ch = cin.peek();

	if (ch >= '0' && ch <= '9')
	{
		int num;
		cin >> num;
		cout << "您输入的是数字： " << num << endl;
	}
	else
	{
		char buf[1024] = "";
		cin >> buf;
		cout << "您输入的是字符串： " << buf << endl;
	}


	system("pause");
	return 0;
}