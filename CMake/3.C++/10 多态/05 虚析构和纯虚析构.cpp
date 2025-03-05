#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
	//虚析构
	//virtual ~Animal()
	//{
	//	cout << "Animal的析构函数调用" << endl;
	//}

	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat : public Animal
{
public:
	Cat(const char* name)
	{
		cout << "Cat的构造函数调用" << endl;
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}

	virtual void speak()
	{
		cout << "小猫" << this->m_Name << "在说话" << endl;
	}

	~Cat()
	{
		if (this->m_Name != NULL)
		{
			cout << "Cat的析构函数调用" << endl;
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}
	char* m_Name;
};


int main()
{

	Animal* animal = new Cat("Tom");
	animal->speak();
	//通过父类指针释放的时候，无法释放子类对象，导致清理不干净
	delete animal;

	//当类中有了纯虚析构，此类也变为抽象类，无法实例化对象
	//Animal* a = new Animal;

	system("pause");
	return 0;
}