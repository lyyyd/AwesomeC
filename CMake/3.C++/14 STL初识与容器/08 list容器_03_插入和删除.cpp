#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
/* 插入
push_back(elem);			//尾部插入元素elem
push_front(elem); 			//头部插入元素elem
insert(const_iterator pos, ele);		//迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
insert(const_iterator pos,beg,end);    	//在pos位置插入[beg,end)区间的数据
*/

void printList(list<int>&L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L); // 300 200 100 10 20 30

	L.insert(L.begin(), 1000);
	printList(L); // 1000 300 200 100 10 20 30

	L.insert(L.begin(), 2, 2000);
	printList(L); // 2000 2000 1000 300 200 100 10 20 30

}


/* 删除
pop_back();				//删除最后一个元素
pop_front();                 			//删除第一个数据
erase(const_iterator pos);		//删除迭代器指向的元素
erase(const_iterator start, const_iterator end);  //删除迭代器从start到end之间的元素
clear();				//删除容器中所有元素
remove(elem);			//删除容器中所有与elem值匹配的元素
*/
void test02()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	L.pop_front();
	printList(L); // 200 100 10 20 30

	L.pop_back();
	printList(L);  //200 100 10 20

	L.erase(++L.begin());
	printList(L);  //200 10 20

	L.push_back(200);
	L.push_back(200);
	L.push_back(200);
	L.remove(200); //将所有200都删除掉
	printList(L);  //10 20

	L.clear();
	printList(L);
}

int main()
{
	test02();


	system("pause");
	return 0;
}