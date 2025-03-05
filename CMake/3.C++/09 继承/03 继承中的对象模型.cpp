#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son :public Base
{
public:
	int m_D;
};
int main()
{
	Son son;
	cout << "sizeof(son) = " << sizeof(son) << endl;

	system("pause");
	return 0;
}