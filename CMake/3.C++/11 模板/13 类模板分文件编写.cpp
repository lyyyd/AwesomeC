#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//#include "person.h"
//#include"person.cpp"
#include "person.hpp"

int main()
{
	Person <string,int> p1("Tom", 30);
	p1.showPerson();

	system("pause");
	return 0;
}