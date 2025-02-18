#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数指针类型
typedef void(*op_t)(void *data);

typedef int(*cmp_t)(void *data, void *key);

//动态数组信息结构体
typedef struct _darr_t {

    //动态数组起始地址 （void*)
    void **data;

    //动态数组元素个数
    int count;

    //动态数组容量
    int capacity;

}darr_t;



//动态数组初始化
darr_t *darr_init(int cap);

//动态数组插入数据
int darr_insert_by_index(darr_t *d, int index, void *data);

//动态数组删除 通过索引
int darr_delete_by_index(darr_t *d, int index);

//动态数组删除 通过关键字
int darr_delete_by_key(darr_t *d, void *key, cmp_t my_cmp);

//动态数组遍历
int darr_traverse(darr_t *d, op_t my_print);

//动态数组销毁
int darr_destroy(darr_t *d);