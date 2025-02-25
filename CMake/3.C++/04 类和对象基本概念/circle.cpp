#include "circle.h"

//设置半径 圆心
void Circle::setR(int r)
{
    m_R = r;
}
void Circle::setCenter(Point center)
{
    m_Center = center;
}

//获取半径 圆心
int Circle::getR()
{
    return m_R;
}

Point Circle::getCenter()
{
    return m_Center;
}

//通过成员函数判断点和圆关系
void Circle::isInCircleByClass(Point& p)
{
    //半径的平方
    int rDis = m_R * m_R;

    //两点的距离的平方
    int dis = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) +
        (m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());

    if (rDis == dis)
    {
        cout << "成员函数判断：点在圆上" << endl;
    }
    else if (rDis > dis)
    {
        cout << "成员函数判断：点在圆内" << endl;
    }
    else
    {
        cout << "成员函数判断：点在圆外" << endl;
    }
}
