#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<set>

/*
交换
swap(st);		//交换两个集合容器

大小
empty();		//判断容器是否为空
size();		//返回容器中元素的个数
*/

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	set<int>s;
	s.insert(10);
	s.insert(30);
	s.insert(20);

	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);

	cout << "交换前 遍历容器的结果为： " << endl;
	printSet(s);
	printSet(s2);
	cout << "--------------------------" << endl;
	s.swap(s2);
	cout << "交换后 遍历容器的结果为： " << endl;
	printSet(s);
	printSet(s2);

	if (s2.empty())
	{
		cout << "s2为空" << endl;
	}
	else
	{
		cout << "s2不为空，大小为： " << s2.size() << endl;
	}

	system("pause");
	return 0;
}