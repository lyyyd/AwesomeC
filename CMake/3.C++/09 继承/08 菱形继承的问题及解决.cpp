#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//动物类
class Animal
{
public:
    int m_Age;
};
//利用虚继承，解决菱形继承的问题，此时Animal类也称为 虚基类
//羊类
class Sheep : virtual public Animal {};
//驼类
class Tuo :virtual public Animal{};
//羊驼类
class SheepTuo : public Sheep, public Tuo{};

void test01()
{
    SheepTuo st;
    //问题一，使用数据不明确，必须加作用域区分
    st.Sheep::m_Age = 10;
    st.Tuo::m_Age = 20;

    //问题二：age属性有一份即可，有两份无法区分用哪个合适，并且会造成资源浪费
    //cout << st.m_Age << endl;
    cout << st.Sheep::m_Age << endl;
    cout << st.Tuo::m_Age << endl;

    cout << sizeof(st) <<endl;
}

void test02()
{
    SheepTuo st;
    st.m_Age = 100;

    //获取到Sheep对应的偏移量
    //*(int*)& st 定位到 Sheep的vbtable表中
    cout << "通过Sheep找到的偏移量： " << *((int*)*(int*)&st + 1) << endl;

    //获取到Tuo对应的偏移量
    //*((int*)& st + 1) 定位到Tuo的vbtable表中
    cout << "通过Tuo找到的偏移量： " << *((int*)*((int*)&st + 1) + 1) << endl;

    //通过偏移量 访问 age 数值
    cout << "m_Age = " << *((int*)((char*)&st + *((int*)*(int*)&st + 1))) << endl;

    cout << "m_Age = " << ((Animal*)((char*)&st + *((int*)*(int*)&st + 1)))->m_Age << endl;

}


int main()
{

//    test01();
    test02();

    system("pause");
    return 0;
}