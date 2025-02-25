#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "point.h"

//圆类
class Circle
{
public:
    //设置半径 圆心
    void setR(int r);

    void setCenter(Point center);

    //获取半径 圆心
    int getR();
    Point getCenter();

    //通过成员函数判断点和圆关系
    void isInCircleByClass(Point& p);


private:
    //半径
    int m_R;
    //圆心
    Point m_Center;
};