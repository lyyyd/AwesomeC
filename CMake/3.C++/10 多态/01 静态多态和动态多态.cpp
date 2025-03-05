#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//动物类
class Animal
{
public:
	//添加virtual  speak变为虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "动物在吃饭" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "小猫在吃饭" << endl;
	}
};

//狗类
class Dog : public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "小狗在吃饭" << endl;
	}
};

//执行说话
void StartSpeak(Animal& animal)
{
	animal.speak();
}

void test01()
{
	Cat cat;
	StartSpeak(cat);

	Dog dog;
	StartSpeak(dog);
}

void test02()
{
	Animal* animal = new Cat;
	animal->speak();

	// *(int *)animal 找到对应的虚函数表
	// *(int *)*(int*)animal 找到对应的speak函数入口地址

//	((void(*)())  (*(int*)*(int*)animal))();

	//animal->eat();
	// C/C++默认调用惯例 为 cdecl
	// C++通常转为stdcall
//	typedef void(__stdcall* FUNC_POINT)(int);
//	(FUNC_POINT(*((int*)*(int*)animal + 1)))(10);
}

int main()
{
//	test01();
	test02();


	system("pause");
	return 0;
}