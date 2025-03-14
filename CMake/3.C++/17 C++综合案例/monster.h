#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "hero.h"
#include "fileManager.h"
#include <map>

//怪物类设计
class Hero;
class Monster
{
public:
    Monster(int monsterId);
    void Attack(Hero* hero);

public:
    string monsterName; //怪物名称
    int monsterHp;   //怪物血量
    int monsterAtk;  //怪物攻击力
    int monsterDef;  //怪物防御力
    bool isFrozen;   //冰冻状态
};