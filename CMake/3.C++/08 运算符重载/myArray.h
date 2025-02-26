#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//数组类
class MyArray
{
public:
	//默认构造
	MyArray();

	//有参构造
	MyArray(int capacity);

	//拷贝构造
	MyArray(const MyArray& arr);

	//根据位置设置数据
	void setData(int pos, int data);

	//根据位置获取数据
	int getData(int pos);

	//尾插
	void pushBack(int data);

	//获取数组的容量
	int getCapacity();

	//获取数组的大小
	int getSize();

	//析构函数
	~MyArray();

	//重载[]
	int& operator[](int pos);


private:
	int m_Capacity; //数组容量
	int m_Size;		//数组大小
	int* pAddress;  //维护创建在堆区数组的指针
};

