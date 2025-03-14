#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>


/*  queue容器常用接口
构造函数：
queue<T> que;		        //queue采用模板类实现，queue对象的默认构造形式
queue(const queue &que);	//拷贝构造函数
赋值操作：
queue& operator=(const queue &que);	  //重载等号操作符
数据存取：
push(elem);		//往队尾添加元素
pop(); 		    //从队头移除第一个元素
back();		    //返回最后一个（队尾）元素
front(); 		//返回第一个（队头）元素
大小操作：
empty();        //判断队列是否为空
size();         //返回队列的大小
*/

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

int main()
{
	queue<Person>q;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "队列的大小： " << q.size() << endl;

	//队列不为空 查看队头 队尾，执行出队
	while (!q.empty())
	{
		Person pFront =  q.front();
		cout << "队头元素姓名： " << pFront.m_Name << " 年龄： " << pFront.m_Age << endl;

		Person pBack = q.back();
		cout << "队尾元素姓名： " << pBack.m_Name << " 年龄： " << pBack.m_Age << endl;

		//出队
		q.pop();
	}

	cout << "队列的大小： " << q.size() << endl;

	system("pause");
	return 0;
}