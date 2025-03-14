#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>

/*  容量和大小
empty();			//判断容器是否为空
capacity();			//容器的容量
size();			    //返回容器中元素的个数
resize(int num);	//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
    				//如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);  	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
    				//如果容器变短，则末尾超出容器长度的元素被删除
*/

void test01()
{
	int arr[] = { 1,2,3,4,5 };
	vector <int>v(arr,arr+sizeof(arr)/sizeof(int));

	if (v.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空，容量：" << v.capacity() << " 大小： " << v.size() << endl;
	}

	v.resize(10,100);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "容量：" << v.capacity() << " 大小： " << v.size() << endl;

}

int main()
{
	test01();


	system("pause");
	return 0;
}