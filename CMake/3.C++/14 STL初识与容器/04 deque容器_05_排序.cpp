#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>
#include <algorithm>

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	cout << "排序前遍历容器结果为： " << endl;
	printDeque(d); // 300 200 100 10 20 30

	sort(d.begin(), d.end());

	cout << "排序后遍历容器结果为： " << endl;
	printDeque(d); // 10 20 30 100 200 300

	system("pause");
	return 0;
}