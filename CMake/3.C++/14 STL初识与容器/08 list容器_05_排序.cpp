#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <algorithm>

void printList(list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;  //降序规则
}

int main()
{
	list<int>L;

	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	L.push_front(400);

	cout << "排序前遍历容器的结果为： " << endl;
	printList(L); //400 300 200 100 10 20 30 40

	L.sort(); //升序

	cout << "升序排列后遍历容器的结果为： " << endl;
	printList(L); //10 20 30 40 100 200 300 400

	L.sort(myCompare); //降序

	cout << "降序排列后遍历容器的结果为： " << endl;
	printList(L); //400 300 200 100 40 30 20 10

	//sort(L.begin(), L.end()); 只能用成员函数sort不能用全局sort算法
	//printList(L); //400 300 200 100 40 30 20 10

	system("pause");
	return 0;
}