#include "broadSword.h"


//构造函数
BroadSword::BroadSword()
{
    FileManager fm;
    map<string, map<string, string>> mWeapon;
    fm.loadCSVData("Weapons.csv", mWeapon);

    //武器id
    string id = mWeapon["2"]["weaponId"];

    //武器名称
    this->weaponName = mWeapon[id]["weaponName"];
    //武器攻击力
    this->baseDamage = atoi(mWeapon[id]["weaponAtk"].c_str());
    //武器暴击系数
    this->critPlus = atoi(mWeapon[id]["weaponCritPlus"].c_str());
    //武器暴击率
    this->critRate = atoi(mWeapon[id]["weaponCritRate"].c_str());
    //武器吸血系数
    this->suckPlus = atoi(mWeapon[id]["weaponSuckPlus"].c_str());
    //武器吸血率
    this->suckRate = atoi(mWeapon[id]["weaponSuckRate"].c_str());
    //武器冰冻率
    this->frozenRate = atoi(mWeapon[id]["weaponFrozenRate"].c_str());
}

//获取基础伤害
int BroadSword::getBaseDamage()
{
    return this->baseDamage;
}

//暴击效果  返回值大于0 触发暴击 否则不触发
int BroadSword::getCrit()
{
    if (isTrigger(this->critRate))
    {
        return this->baseDamage * this->critPlus;
    }
    else
    {
        return 0;
    }
}

//吸血效果 返回值大于0 触发吸血 否则不触发
int BroadSword::getSuckBlood()
{
    if (isTrigger(this->suckRate))
    {
        return this->baseDamage * this->suckPlus;
    }
    else
    {
        return 0;
    }

}

//冰冻效果 返回true代表触发 否则不触发
bool BroadSword::getFrozen()
{
    if (isTrigger(this->frozenRate))
    {
        return true;
    }
    else
    {
        return false;
    }

}

//触发概率的算法
bool BroadSword::isTrigger(int rate)
{
    int num = rand() % 100 + 1;  // 1 ~ 100
    if (num <= rate)
    {
        return true;
    }
    return false;

}