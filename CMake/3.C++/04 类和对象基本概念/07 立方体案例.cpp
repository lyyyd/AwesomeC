#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//立方体类
class Cube
{
public:
	//设置长
	void setL(int l)
	{
		m_L = l;
	}
	//获取长
	int getL()
	{
		return m_L;
	}

	//设置宽
	void setW(int w)
	{
		m_W = w;
	}

	//获取宽
	int getW()
	{
		return m_W;
	}

	//设置高
	void setH(int h)
	{
		m_H = h;
	}

	//获取高
	int getH()
	{
		return m_H;
	}

	//获取面积
	int getS()
	{
		return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
	}

	//获取体积
	int getV()
	{
		return m_L * m_W * m_H;
	}

	//成员函数检测两个立方体是否相等  c1.compareCubeByClass(c2)
	bool compareCubeByClass(Cube & c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

private:
	//长
	int m_L;
	//宽
	int m_W;
	//高
	int m_H;
};

//全局函数判断两个立方体是否相等
bool compareCube(Cube &c1, Cube &c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	return false;
}

void test01()
{
	//创建第一个立方体对象
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout << "c1的面积为： " << c1.getS() << endl; //600
	cout << "c1的体积为： " << c1.getV() << endl; //1000

	//创建第二个立方体对象
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	bool ret = compareCube(c1, c2);
	if (ret)
	{
		cout << "全局函数检测结果为 ：c1和c2相等" << endl;
	}
	else
	{
		cout << "全局函数检测结果为 ：c1和c2不相等" << endl;
	}

	ret = c1.compareCubeByClass(c2);
	if (ret)
	{
		cout << "成员函数检测结果为 ：c1和c2相等" << endl;
	}
	else
	{
		cout << "成员函数检测结果为 ：c1和c2不相等" << endl;
	}
}

int main()
{
	test01();


	system("pause");
	return 0;
}