#include <iostream>
using namespace std;

//1、using声明
//语法：using 命名空间名称::变量名
namespace LOL
{
    int heroId = 1;
}

void test01()
{
    //当using声明碰到就近原则，会产生二义性，编译器无法识别
    int heroId = 2;
    //using LOL::heroId;
    cout << heroId << endl;
}

namespace KingGlory
{
    int heroId = 10;
}

//2、using编译指令
//语法：using namespace 命名空间名称
void test02()
{
    //当using编译指令碰到就近原则，会优先使用就近原则
    int heroId = 3;
    using namespace LOL;
    using namespace KingGlory;
    //当多个命名空间下有同名变量，使用时候依然需要加上作用域
    cout << LOL::heroId << endl;
    cout << KingGlory::heroId << endl;
    cout << heroId << endl;
}

int main()
{
    test02();

    system("pause");
    return 0;
}