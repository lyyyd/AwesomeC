#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
    char * p = NULL;
    // 给p指针的内存区域拷贝内容
    strcpy(p, "1111"); // err

//    char * q = 0x1122;
//    // 给q指针的内存区域拷贝内容
//    strcpy(q, "2222"); // err
}

int * doWork()
{
    int a = 10;
    int *p = &a;
    return  p;
}

// 野指针的情况
void test02()
{
    //1. 声明未初始化的指针
//    int *p;
//    printf("%d\n", *p);

    // 2. malloc后free的指针
    int * q = malloc(sizeof(int));
    *q = 100;
    printf("%d\n", *q);

    free(q);
    printf("%d\n", *q);

//    *q = 1000; // 不要操作野指针
    q = NULL;

    // 3. 指针变量超出了作用域
    int* p2 = doWork();
    printf("p2 = %d\n", *p2);
    printf("p2 = %d\n", *p2);

    // 空指针是否可以重复释放 - 可以
    free(q);
    // 野指针是否可以重复释放 - 不可以
//    free(q);
}

int main(){
//    test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}