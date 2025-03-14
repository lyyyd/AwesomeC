#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//武器基类
class Weapon
{
public:
    //获取基础伤害
    virtual int getBaseDamage() = 0;

    //暴击效果  返回值大于0 触发暴击 否则不触发
    virtual int getCrit() = 0;

    //吸血效果 返回值大于0 触发吸血 否则不触发
    virtual int getSuckBlood() = 0;

    //冰冻效果 返回true代表触发 否则不触发
    virtual bool getFrozen() = 0;

    //触发概率的算法
    virtual bool isTrigger(int rate) = 0;

public:
    int baseDamage;   //武器基础攻击力
    string weaponName;  //武器名称
    int critPlus;       //武器暴击系数
    int critRate;       //暴击率
    int suckPlus;       //吸血系数
    int suckRate;       //吸血率
    int frozenRate;     //冰冻率
};