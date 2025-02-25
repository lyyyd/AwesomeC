#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//点类
class Point
{
public:
    //设置x、y
    void setX(int x);

    void setY(int y);

    //获取x、y
    int getX();

    int getY();

private:
    int m_X; //x坐标
    int m_Y; //y坐标
};