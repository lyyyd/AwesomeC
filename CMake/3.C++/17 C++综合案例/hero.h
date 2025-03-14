#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "weapon.h"
#include "fileManager.h"
#include <map>
#include <string>
#include "monster.h"

class Monster;
class Hero
{
public:

    //构造函数
    Hero(int heroId);

    //攻击函数
    void Attack(Monster* monster);

    //装备武器
    void EquipWeapon(Weapon* weapon);

public:
    //英雄HP
    int heroHp;
    //英雄攻击力
    int heroAtk;
    //英雄防御力
    int heroDef;
    //英雄姓名
    string heroName;
    //英雄简介
    string heroInfo;
    //武器指针
    Weapon* weapon;
};