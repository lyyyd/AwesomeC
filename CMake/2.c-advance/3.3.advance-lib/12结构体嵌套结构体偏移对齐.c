#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


#pragma pack(2)
struct A
{
    double a;//8
    int b;//4->4  8
    double c;//8
    char d;//1->7 8
};
struct B
{
    struct A a;//32
    int b;//4
    char c[13];//4  8 1->1
    short d;//2 ->4
};
int main12()
{
    printf("%d\n", sizeof(struct B));
    return EXIT_SUCCESS;
}
