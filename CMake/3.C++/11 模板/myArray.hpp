#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:

    //有参构造 参数容量
    explicit MyArray(int capacity)  // MyArray arr = 10 ;
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress =  new T[this->m_Capacity];
    }

    //拷贝构造
    MyArray(const MyArray& arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator =
    MyArray& operator=(const MyArray& arr)
    {
        //先判断是否有数据，如果有先清空
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //析构
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

    //operator[]
    T& operator[] (int pos)
    {
        return this->pAddress[pos];
    }

    //尾插
    void push_back(T val)
    {
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //尾删
    void pop_back()
    {
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    //获取数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //获取数组大小
    int getSize()
    {
        return this->m_Size;
    }

private:
    int m_Capacity; //数组容量
    int m_Size; //数组大小
    T* pAddress; //指向堆区数组指针
};
