#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Room;
class GoodFriend
{
public:
    GoodFriend();
    void visit1();
    void visit2();
    Room* room;
};

class Room
{
    friend void GoodFriend::visit1();
public:
    Room();

    string m_SittingRoom;
private:
    string m_BedRoom;
};

//类外实现
GoodFriend::GoodFriend()
{
    room = new Room;
}

void GoodFriend::visit1()
{
    cout << "好朋友visit1成员函数正在访问：" << room->m_SittingRoom << endl;
    cout << "好朋友visit1成员函数正在访问：" << room->m_BedRoom << endl;
}
void GoodFriend::visit2()
{
    cout << "好朋友visit2成员函数正在访问：" << room->m_SittingRoom << endl;
    //cout << "好朋友visit2成员函数正在访问：" << room->m_BedRoom << endl;
}

Room::Room()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

int main()
{

    GoodFriend gf;
    gf.visit1();
    gf.visit2();

    system("pause");
    return 0;
}