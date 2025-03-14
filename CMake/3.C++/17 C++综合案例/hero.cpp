#include "hero.h"

//构造函数
Hero::Hero(int heroId)
{
    FileManager fm;
    map<string, map<string, string>> mHero;
    fm.loadCSVData("Hero.csv", mHero);

    //int -> string
    string hid = std::to_string(heroId);

    //英雄id
    string id = mHero[hid]["heroId"];
    //英雄姓名
    this->heroName = mHero[id]["heroName"];
    //英雄攻击力
    this->heroAtk = atoi( mHero[id]["heroAtk"].c_str() );
    //英雄防御力
    this->heroDef = atoi(mHero[id]["heroDef"].c_str());
    //英雄血量
    this->heroHp = atoi(mHero[id]["heroHp"].c_str());
    //英雄简介
    this->heroInfo = mHero[id]["heroInfo"];
    //武器指针
    this->weapon = NULL;
}

//装备武器
void Hero::EquipWeapon(Weapon* weapon)
{
    if (weapon == NULL)
    {
        return;
    }
    this->weapon = weapon;
    cout << "英雄： " << this->heroName << "装备了武器 《 " << this->weapon->weaponName << " 》！" << endl;
}



//攻击函数
void Hero::Attack(Monster* monster)
{
    int crit = 0;  //暴击
    int suck = 0;  //吸血
    bool forzen = 0;  //冰冻
    int damage = 0;   //伤害

    if (this->weapon == NULL)
    {
        damage = this->heroAtk;  //没有装备武器，伤害为英雄攻击力
    }
    else
    {
        damage = this->heroAtk + this->weapon->getBaseDamage(); //有武器，伤害等于 自身攻击力 + 武器攻击力

        crit = this->weapon->getCrit();

        suck = this->weapon->getSuckBlood();

        forzen = this->weapon->getFrozen();
    }

    //判断特效
    if (crit)
    {
        damage += crit;
        cout << "英雄的武器触发了暴击效果" << monster->monsterName << "受到暴击伤害" << endl;
    }
    if (suck)
    {
        cout << "英雄的武器触发了吸血效果,英雄增加了血量： " << suck << endl;
    }
    if (forzen)
    {
        cout << "英雄的武器触发了冰冻效果，怪物" << monster->monsterName << "停止攻击一回合！" << endl;
    }

    monster->isFrozen = forzen; //给怪物冰冻状态赋值
    this->heroHp += suck;  //血量增加
    int trueDamage = damage - monster->monsterDef > 0 ? damage - monster->monsterDef : 1;
    //怪物掉血
    monster->monsterHp -= trueDamage;

    cout << "英雄： " << this->heroName << "攻击了怪物： " << monster->monsterName << " 造成伤害： " << trueDamage << endl;
}