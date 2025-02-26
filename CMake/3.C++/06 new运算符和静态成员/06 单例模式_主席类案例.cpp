#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//单例模式 主席类案例
class ChairMan
{
public:

	//getInstance获取单例模式中的唯一实例对象
	static ChairMan* getInstance()
	{
		return singleMan;
	}


private:
	//默认构造私有化
	ChairMan() {
		//cout << "默认构造函数调用" << endl;
	}

	//拷贝构造私有化
	ChairMan(const ChairMan& man)
	{}

	//静态成员属性 指向唯一主席对象
	static ChairMan* singleMan;
};
ChairMan* ChairMan::singleMan = new ChairMan;


void test01()
{
	//ChairMan c1;
	//ChairMan c2;
	//ChairMan *c3 = new ChairMan;

	//ChairMan * c1 = ChairMan::singleMan;
	//ChairMan * c2 = ChairMan::singleMan;

	ChairMan* c1 = ChairMan::getInstance();
	ChairMan* c2 = ChairMan::getInstance();
	//ChairMan* c3 = new ChairMan(*c1);
	if (c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}

	//ChairMan::singleMan = NULL;
}

int main()
{
	//cout << "hello world" << endl;
	test01();

	system("pause");
	return 0;
}