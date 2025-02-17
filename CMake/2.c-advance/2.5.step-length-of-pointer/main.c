#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


// 指针的步长
// 1. 指针步长+1 后 跳跃的字节数
void test01()
{
    char * p = NULL;

    printf("%d\n", p);
    printf("%d\n", p + 1);

    double * p2 = NULL;
    printf("%d\n",p2);
    printf( "%d\n",p2 + 1);
}

//2. 在解引用的时候 取出字节数
void test02()
{
    char buf[1024] = {0};
    int a = 1000;
    memcpy(buf, &a, sizeof(int));

    char * p = buf;
    printf("%d\n", *(int *)p);

    char buf1[1024] = {0};
    int a1 = 1000;
    memcpy(buf1+1, &a1, sizeof(int));

    char * p1 = buf1;
    printf("%d\n", *((int *)(p1+1)) );
}

// 指针步长的练习
struct Person
{
    char a; // 0 - 3
    int b; // 4 - 7
    char buf[64]; // 8 - 71
    int d; // 72 - 75
};

void test03()
{
    struct  Person p = {'a', 10, "Hello World!", 10000};

    // p中 d的偏移量是多少
    printf("d 的偏移量是: %d\n", offsetof(struct  Person,  d));
    printf("d 的值是: %d\n", *(int * )((char *)&p + offsetof(struct  Person,  d)));

}

int main(){
//    test01();
//    test02();
    test03();

    system("pause");
    return EXIT_SUCCESS;
}