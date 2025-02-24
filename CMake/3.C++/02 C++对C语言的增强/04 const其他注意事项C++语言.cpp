#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//在C++下 全局变量前加const 默认是内部链接属性
void test01()
{
    extern const int g_b;
    cout << g_b << endl;

}

//const分配内存情况
//对const修饰的变量取地址时，会分配临时内存
void test02()
{
    const int m_a = 10;
    int* p = (int *) & m_a;  //创建临时数据temp ，分配内存 , int * p = &temp;
    *p = 1000;
    cout << *p << endl;
    cout << m_a << endl;
}

void test03()
{
    //使用变量初始化 const修饰的变量，数据会放在栈区
    int num = 100;
    const int m_a = num;  //m_a放在栈区
    int* p = (int*)&m_a;
    *p = 1000;
    cout << *p << endl;
    cout << m_a << endl;
}
//对于自定义数据类型，也是放在栈区
struct Person
{
    int age = 10;
};

void test04()
{
    const Person p;
    //p.age = 20;
    Person* pp = (Person*)&p;
    pp->age = 20;
    cout << "年龄： " << p.age << endl;
}

//尽量用const代替define
void test05()
{
    //1、宏常量不重视作用域
#define PI 3.14

    //2、宏常量 没有数据类型之分

    const double Pi = 3.14;
}

int main()
{
    //test04();

    //cout << Pi << endl;

    system("pause");
    return 0;
}