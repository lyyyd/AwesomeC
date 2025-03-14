#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>

/*
插入
push_back(elem);			//尾部插入元素elem
push_front(elem); 			//头部插入元素elem
insert(const_iterator pos, ele);		//迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
insert(const_iterator pos,beg,end);    	//在pos位置插入[beg,end)区间的数据
删除
pop_back();				    //删除最后一个元素
pop_front();                //删除第一个数据
erase(const_iterator pos);	//删除迭代器指向的元素
erase(const_iterator start, const_iterator end);  //删除迭代器从start到end之间的元素
clear();				    //删除容器中所有元素
*/

void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	d.push_back(50);
	printDeque(d);

	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printDeque(d);  // 300 200 100 10 20 30 40 50

	d.insert(d.begin() + 1, 1000);
	printDeque(d);  // 300 1000 200 100 10 20 30 40 50

	d.insert(d.begin() + 4, 2, 2000);
	printDeque(d);  // 300 1000 200 100 2000 2000 10 20 30 40 50

	deque<int>d2(4, 555);
	d.insert(d.begin(), d2.begin(), d2.end());

	printDeque(d);  // 555 555 555 555 300 1000 200 100 2000 2000 10 20 30 40 50


	d.pop_front();
	d.pop_back();
	printDeque(d); // 555 555 555 300 1000 200 100 2000 2000 10 20 30 40

	deque<int>::iterator it = d.begin();
	it = it + 4;
	d.erase(it);
	printDeque(d); // 555 555 555 300 200 100 2000 2000 10 20 30 40

	deque<int>::iterator it1 = d.begin();
	deque<int>::iterator it2 = d.begin() + 3;
	d.erase(it1, it2);
	printDeque(d); // 300 200 100 2000 2000 10 20 30 40

	d.clear();
	printDeque(d);
}

int main()
{

	test01();

	system("pause");
	return 0;
}