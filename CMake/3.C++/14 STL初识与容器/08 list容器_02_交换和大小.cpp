#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>

/*
交换
swap(lst);          //将lst与本身的元素互换
大小
empty();			//判断容器是否为空
size();				//返回容器中元素的个数
resize(int num);	//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
					//如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);  	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
					//如果容器变短，则末尾超出容器长度的元素被删除
*/

void printList(list<int> & L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	list<int>L1(10, 100);
	list<int>L2(10, 200);

	cout << "L1和L2互换前，遍历结果： " << endl;
	printList(L1);
	printList(L2);

	L1.swap(L2);

	cout << "L1和L2互换后，遍历结果： " << endl;
	printList(L1);
	printList(L2);

	list<double>L3(10, 1.1);
	//L1.swap(L3); //L1和L3存储类型不同，互换失败

	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空，大小： " << L1.size() << endl;
	}

	L1.resize(15);
	printList(L1);

	L1.resize(4);
	printList(L1);

	system("pause");
	return 0;
}