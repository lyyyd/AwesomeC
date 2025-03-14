#include "monster.h"

Monster::Monster(int monsterId)
{
    FileManager fm;
    map<string, map<string, string>> mMonster;
    fm.loadCSVData("Monsters.csv", mMonster);

    string tmpId = to_string(monsterId);

    //怪物Id
    string id = mMonster[tmpId]["monsterId"];

    //名称
    this->monsterName = mMonster[id]["monsterName"];

    //攻击力
    this->monsterAtk = atoi( mMonster[id]["monsterAtk"].c_str());

    //防御力
    this->monsterDef = atoi(mMonster[id]["monsterDef"].c_str());

    //血量
    this->monsterHp = atoi(mMonster[id]["monsterHp"].c_str());

    //冰冻状态
    this->isFrozen = false;
}



void Monster::Attack(Hero* hero)
{
    //判断是否被冰冻
    if (this->isFrozen)
    {
        cout << "怪物：" << this->monsterName << "被冰冻了，本回合无法进行攻击！" << endl;
        return;
    }

    //计算伤害
    int damage = this->monsterAtk - hero->heroDef > 0 ? this->monsterAtk - hero->heroDef : 1;
    //英雄掉血
    hero->heroHp -= damage;
    //提示信息
    cout << "怪物： " << this->monsterName << "攻击了英雄： " << hero->heroName << " 造成伤害： " << damage << endl;

}