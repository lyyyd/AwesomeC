#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象制作饮品类
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;

	//制作流程
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡类
class Coffee :public AbstractDrinking
{
public:

	//煮水
	virtual void Boil()
	{
		cout << "煮农夫山泉" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "将咖啡倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入牛奶" << endl;
	}
};

//制作茶水类
class Tea :public AbstractDrinking
{
public:

	//煮水
	virtual void Boil()
	{
		cout << "煮自来水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "将茶水倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入枸杞" << endl;
	}

};

//业务逻辑函数
void DoWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}

int main()
{
	//制作咖啡
	DoWork(new Coffee);

	cout << "------------------" << endl;
	//制作茶水
	DoWork(new Tea);

	system("pause");
	return 0;
}