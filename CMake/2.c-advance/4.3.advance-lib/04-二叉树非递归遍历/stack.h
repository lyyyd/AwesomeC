#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//链式栈设计

//函数指针类型
typedef void(*op_t)(void *data);

//节点类型
typedef struct _node_t {
    //数据域
    void *data;
    //指针域
    struct _node_t *next;
}node_t;

//头信息结构体 管理链式栈
typedef struct _stack_t {
    //栈顶指针
    node_t *top;
    //数据域元素大小
    int size;
    //栈中元素个数
    int count;
    //自定义销毁函数
    op_t my_destroy;
}stack_t;

//初始化
stack_t *stack_init(int size, op_t my_destroy);

//进栈
int stack_push(stack_t *s, void *data);

//出栈
int stack_pop(stack_t *s, void *data);

//返回栈顶元素
int stack_top(stack_t *s, void *data);

//返回栈中元素个数
int stack_count(stack_t *s);

//判断栈是否为空
int stack_is_empty(stack_t *s);

//销毁
int stack_destroy(stack_t *s);
