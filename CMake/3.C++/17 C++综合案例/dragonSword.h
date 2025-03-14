#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "weapon.h"
#include "fileManager.h"
#include <map>

//屠龙刀类
class DragonSword :public Weapon
{
public:
    //构造函数
    DragonSword();

    //获取基础伤害
    virtual int getBaseDamage();

    //暴击效果  返回值大于0 触发暴击 否则不触发
    virtual int getCrit();

    //吸血效果 返回值大于0 触发吸血 否则不触发
    virtual int getSuckBlood();

    //冰冻效果 返回true代表触发 否则不触发
    virtual bool getFrozen();

    //触发概率的算法
    virtual bool isTrigger(int rate);
};

