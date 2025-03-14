#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>
/*
插入
insert(elem);		//在容器中插入元素

删除
erase(pos);		    //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);	//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);		//删除容器中值为elem的元素。
clear();		    //清除所有元素
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
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(50);

	s.erase(++s.begin());

	printSet(s);  //  10 30 40 50

	set<int>::iterator it1 = s.begin();
	++it1;
	set<int>::iterator it2 = s.begin();
	(++(++(++it2)));
	s.erase(it1, it2);
	printSet(s);  //  10 50

	s.erase(10);
	printSet(s);  //  50

	s.clear();
	printSet(s);

	system("pause");
	return 0;
}