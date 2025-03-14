#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
/*
插入
push_back(ele);			//尾部插入元素ele
insert(const_iterator pos, ele);		//迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele

删除
pop_back();				//删除最后一个元素
erase(const_iterator pos);		//删除迭代器指向的元素
erase(const_iterator start, const_iterator end);  //删除迭代器从start到end之间的元素
clear();				//删除容器中所有元素
*/

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	printVector(v);

	v.insert(v.begin(), 100);
	printVector(v);  //100 10 20 30 40 50

	v.insert(v.begin(), 2, 200);
	printVector(v);  //200 200 100 10 20 30 40 50

	v.pop_back();
	printVector(v);  //200 200 100 10 20 30 40

	vector<int>::iterator it = v.begin();
	v.erase(it + 2);
	printVector(v);  //200 200 10 20 30 40

	vector<int>::iterator it1 = v.begin();
	vector<int>::iterator it2 = v.begin();
	it1 = it1 + 1;
	it2 = it2 + 3;
	v.erase(it1, it2);
	printVector(v);  //200 20 30 40

	//清空容器
	v.clear();
	printVector(v);
}
int main()
{

	test01();

	system("pause");
	return 0;
}