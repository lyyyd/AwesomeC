#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Room
{
	friend void goodFriend(Room& room);
public:
	Room()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

	string m_SittingRoom; //客厅
private:
	string m_BedRoom; //卧室
};

//全局函数 goodFriend
void goodFriend(Room& room)
{
	cout << "好朋友正在访问： " << room.m_SittingRoom << endl;
	cout << "好朋友正在访问： " << room.m_BedRoom << endl;
}

//全局函数 badFriend
void badFriend(Room& room)
{
	cout << "坏朋友正在访问： " << room.m_SittingRoom << endl;
	//cout << "坏朋友正在访问： " << room.m_BedRoom << endl;
}


int main()
{

	Room * room = new Room;
	goodFriend(*room);
	badFriend(*room);

	system("pause");
	return 0;
}