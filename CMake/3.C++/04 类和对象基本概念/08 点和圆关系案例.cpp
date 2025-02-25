#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "point.h"
#include "circle.h"

////点类
//class Point
//{
//public:
//	//设置x、y
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//获取x、y
//	int getX()
//	{
//		return m_X;
//	}
//	int getY()
//	{
//		return m_Y;
//	}
//
//private:
//	int m_X; //x坐标
//	int m_Y; //y坐标
//};

////圆类
//class Circle
//{
//public:
//	//设置半径 圆心
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//
//	//获取半径 圆心
//	int getR()
//	{
//		return m_R;
//	}
//
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//	//通过成员函数判断点和圆关系
//	void isInCircleByClass(Point & p)
//	{
//		//半径的平方
//		int rDis = m_R * m_R;
//
//		//两点的距离的平方
//		int dis = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) +
//			(m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());
//
//		if (rDis == dis)
//		{
//			cout << "成员函数判断：点在圆上" << endl;
//		}
//		else if (rDis > dis)
//		{
//			cout << "成员函数判断：点在圆内" << endl;
//		}
//		else
//		{
//			cout << "成员函数判断：点在圆外" << endl;
//		}
//	}
//
//private:
//	//半径
//	int m_R;
//	//圆心
//	Point m_Center;
//};

//全局函数判断点和圆关系
void isInCircle(Circle & c ,Point & p)
{
    //半径的平方
    int rDis = c.getR() * c.getR();

    //两点的距离的平方
    int dis = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

    if (rDis == dis)
    {
        cout << "点在圆上" << endl;
    }
    else if (rDis > dis)
    {
        cout << "点在圆内" << endl;
    }
    else
    {
        cout << "点在圆外" << endl;
    }
}

int main()
{

    //圆对象
    Circle c;
    c.setR(10);

    Point center;
    center.setX(10);
    center.setY(10);
    c.setCenter(center);

    //点对象
    Point p;
    p.setX(10);
    p.setY(20);

    //全局函数测试
    isInCircle(c, p);

    //成员函数测试
    c.isInCircleByClass(p);


    system("pause");
    return 0;
}