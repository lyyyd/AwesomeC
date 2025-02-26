#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Room;
class GoodFriend
{
public:
	GoodFriend();
	void visit();
	Room* room;
};

class Room
{
	friend class GoodFriend;
public:
	Room(); //构造函数
	string m_SittingRoom; //客厅
private:
	string m_BedRoom; //卧室
};

//类外实现
GoodFriend::GoodFriend()
{
	room = new Room;
}

void GoodFriend::visit()
{
	cout << "好朋友正在访问： " << room->m_SittingRoom << endl;
	cout << "好朋友正在访问： " << room->m_BedRoom << endl;
}

Room::Room()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

int main()
{
	GoodFriend gf;
	gf.visit();


	system("pause");
	return 0;
}