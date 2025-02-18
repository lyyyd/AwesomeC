#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//函数指针类型
typedef void(*op_t)(void *data);

//头信息结构体
typedef struct _stack_t {
    //指向数组起始地址
    void *data;
    //栈顶索引
    int top;
    //栈中每个元素的大小
    int size;
    //栈中元素最大个数
    int max;
    //释放内存函数
    op_t my_destroy;
}stack_t;

//栈初始化
stack_t *stack_init(int size, int max, op_t my_destroy);

//进栈
int stack_push(stack_t *s, void *data);

//出栈
int stack_pop(stack_t *s, void *data);

//判断栈是否满
int stack_is_full(stack_t *s);

//判断栈是否为空
int stack_is_empty(stack_t *s);

//返回栈中元素的个数
int stack_count(stack_t *s);

//返回栈顶元素
int stack_top(stack_t *s, void *data);

//栈的销毁
int stack_destroy(stack_t *s);




