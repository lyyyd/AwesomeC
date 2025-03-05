#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
	}
	int m_Num1;
	int m_Num2;
};

//利用多态实现计算器案例
class AbstractCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}

	int m_Num1;
	int m_Num2;
};
//加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return this->m_Num1 + this->m_Num2;
	}
};

//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return this->m_Num1 - this->m_Num2;
	}
};

//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return this->m_Num1 * this->m_Num2;
	}
};

// 开闭原则：对扩展进行开放  对修改进行关闭

int main()
{
	AbstractCalculator* abs = new AddCalculator;
	abs->m_Num1 = 10;
	abs->m_Num2 = 20;
	cout << abs->getResult() << endl;
	delete abs;

	abs = new SubCalculator;
	abs->m_Num1 = 10;
	abs->m_Num2 = 20;
	cout << abs->getResult() << endl;
	delete abs;

	system("pause");
	return 0;
}