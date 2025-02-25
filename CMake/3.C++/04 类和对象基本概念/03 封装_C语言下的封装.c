#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//人的结构体
struct Person
{
	char Name[64];
};
//吃饭 人
void personEat(struct Person* p)
{
	printf("%s在吃饭\n", p->Name);
}

//狗的结构体
struct Dog
{
	char Name[64];
};
//吃饭 狗
void dogEat(struct Dog* d)
{
	printf("%s在吃狗粮\n", d->Name);
}

void test01()
{
	struct Person p;
	strcpy(p.Name, "张三");
	personEat(&p);

	struct Dog d;
	strcpy(d.Name, "旺财");
	dogEat(&d);
}

void test02()
{
	struct Person p;
	strcpy(p.Name, "张三");
	dogEat(&p);

	//C封装缺陷：
	//1、指针的操作不安全
	//2、行为和属性分离，导致组织结构不清晰
	//3、成员的安全性保证差
}

int main()
{
	test02();


	system("pause");
	return EXIT_SUCCESS;
}