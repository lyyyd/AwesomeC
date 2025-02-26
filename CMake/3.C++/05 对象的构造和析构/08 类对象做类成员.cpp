#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//手机类
class Phone
{
public:

	Phone(string pName)
	{
		cout << "Phone的构造函数调用" << endl;
		m_PhoneName = pName;
	}

	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}
	string m_PhoneName;
};

//游戏类
class Game
{
public:

	Game(string gName)
	{
		cout << "Game的构造函数调用" << endl;
		m_GameName = gName;
	}

	~Game()
	{
		cout << "Game的析构函数调用" << endl;
	}
	string m_GameName;
};

//玩家类
class Player
{
public:

	Player(string name, string phone, string game) : m_Name(name), m_Phone(phone), m_Game(game)
	{
		cout << "Player的构造函数调用" << endl;
	}

	void playGame()
	{
		cout << "姓名： " << m_Name << "拿着《" << m_Phone.m_PhoneName << "》牌的手机，玩着《" << m_Game.m_GameName << "》" << endl;
	}

	~Player()
	{
		cout << "Player的析构函数调用" << endl;
	}
	string m_Name; //姓名
	Phone m_Phone; //手机
	Game  m_Game;  //游戏
};

//当其他类作为本类中成员，先构造其他类的对象，再构造自身，析构的顺序与构造相反
void test01()
{
	Player p1("张三", "苹果", "消消乐");
	p1.playGame();
}

int main()
{
	test01();


	system("pause");
	return 0;
}