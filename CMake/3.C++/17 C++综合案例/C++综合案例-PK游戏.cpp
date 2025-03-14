#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "fileManager.h"
#include <map>
#include "weapon.h"
#include "knife.h"
#include "broadSword.h"
#include "dragonSword.h"
#include "hero.h"
#include "monster.h"
#include <ctime>

void Fighting()
{
    cout << "欢迎参加天下第一武道大会" << endl;
    cout << "请选择您的英雄：" << endl;

    //展示英雄
    FileManager fm;
    map<string, map<string, string>> m_Hero;
    fm.loadCSVData("Hero.csv", m_Hero);

    char buf[1024] = "";
    sprintf(buf, "1、%s[%s]", m_Hero["1"]["heroName"].c_str(), m_Hero["1"]["heroInfo"].c_str());
    cout << buf << endl;
    sprintf(buf, "2、%s[%s]", m_Hero["2"]["heroName"].c_str(), m_Hero["2"]["heroInfo"].c_str());
    cout << buf << endl;
    sprintf(buf, "3、%s[%s]", m_Hero["3"]["heroName"].c_str(), m_Hero["3"]["heroInfo"].c_str());
    cout << buf << endl;

    int select = 0;
    cin >> select;
    getchar();

    //创建英雄
    Hero hero(select);
    cout << "您选择的英雄是： " << hero.heroName << endl;

    //展示武器
    cout << "请给您的英雄选择武器： " << endl;

    map<string, map<string, string>> m_Weapon;
    fm.loadCSVData("Weapons.csv", m_Weapon);
    cout << "1、赤手空拳" << endl;
    sprintf(buf, "2、%s", m_Weapon["1"]["weaponName"].c_str());
    cout << buf << endl;
    sprintf(buf, "3、%s", m_Weapon["2"]["weaponName"].c_str());
    cout << buf << endl;
    sprintf(buf, "4、%s", m_Weapon["3"]["weaponName"].c_str());
    cout << buf << endl;

    //接受用户选择的武器
    cin >> select;
    getchar();

    Weapon* weapon = NULL;
    switch (select)
    {
        case 1:
            cout << "您真自信，请加油吧！" << endl;
            break;
        case 2:
            weapon = new Knife;
            break;
        case 3:
            weapon = new BroadSword;
            break;
        case 4:
            weapon = new DragonSword;
            break;
    }

    //装备武器
    hero.EquipWeapon(weapon);

    //创建随机怪物 1 ~ 5
    int id = rand()%5 + 1;
    Monster monster(id);
    int round = 1; //回合数
    while (true)
    {
        getchar();
        system("cls");
        cout << "------------当前为第" << round << "回合------------" << endl;
        if (hero.heroHp <= 0)
        {
            cout << "英雄死亡，游戏结束，请再接再厉" << endl;
            break;
        }
        //英雄攻击怪物
        hero.Attack(&monster);

        if (monster.monsterHp <= 0)
        {
            cout << "怪物死亡，游戏结束，恭喜您顺利通关！" << endl;
            break;
        }
        //怪物攻击英雄
        monster.Attack(&hero);

        cout << "英雄的剩余血量： " << hero.heroHp << endl;
        cout << "怪物的剩余血量： " << monster.monsterHp << endl;

        if (hero.heroHp <= 0)
        {
            cout << "英雄死亡，游戏结束，请再接再厉" << endl;
            break;
        }
        round++;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    //FileManager fm;
    //map<string, map<string, string>> m_Hero;
    //fm.loadCSVData("Hero.csv", m_Hero);

    //cout << "第一个英雄姓名： " << m_Hero["1"]["heroName"] << endl;
    //cout << "第二个英雄血量： " << m_Hero["2"]["heroHp"] << endl;
    //cout << "第三个英雄攻击力： " << m_Hero["3"]["heroAtk"] << endl;

    //map<string, map<string, string>> m_Weapon;
    //fm.loadCSVData("Weapons.csv", m_Weapon);
    //cout << "第一把武器的名称： " << m_Weapon["1"]["weaponName"] << endl;
    //cout << "第二把武器的攻击力： " << m_Weapon["2"]["weaponAtk"] << endl;

    ////测试 武器多态
    //Weapon* weapon = new Knife;
    //cout << weapon->getBaseDamage() << endl;
    //cout << weapon->weaponName << endl;
    //cout << weapon->frozenRate << endl;
    //delete weapon;

    //weapon = new BroadSword;
    //cout << weapon->getBaseDamage() << endl;
    //cout << weapon->weaponName << endl;
    //cout << weapon->frozenRate << endl;
    //delete weapon;

    //weapon = new DragonSword;
    //cout << weapon->getBaseDamage() << endl;
    //cout << weapon->weaponName << endl;
    //cout << weapon->frozenRate << endl;
    //delete weapon;

    //Hero hero(1);
    //cout << hero.heroName << " " << hero.heroInfo << endl;
    //Hero hero2(2);
    //cout << hero2.heroName << " " << hero2.heroInfo << endl;

    //Monster monster(5);
    //cout << monster.monsterName << " " << monster.monsterAtk << endl;

    //Monster monster2(4);
    //cout << monster2.monsterName << " " << monster2.monsterDef << endl;

    Fighting();

    system("pause");
    return 0;
}