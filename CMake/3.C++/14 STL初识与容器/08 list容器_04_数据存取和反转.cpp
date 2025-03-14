#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>

/*
数据存取
front();	//返回第一个元素。
back();	//返回最后一个元素。

反转
reverse();	//反转链表
*/

void test01()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	//300 200 100 10 20 30
	cout << "第一个数据为： " << L.front() << endl;
	cout << "最后一个数据为多少： " << L.back() << endl;

	L.reverse();
	//30 20 10 100 200 300
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//cout << L[0] << endl; //error 没有 [] 或 at方式访问数据

}

int main()
{
	test01();


	system("pause");
	return 0;
}