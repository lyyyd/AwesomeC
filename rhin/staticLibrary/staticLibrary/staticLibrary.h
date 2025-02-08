//#pragma once
//// staticLibrary.h
//// 声明 add 函数
//int add(int a, int b);


// 定义静态库函数封装结构体
typedef struct {
    int (*add)(int a, int b);
} StaticLibrary;

// 获取静态库函数封装结构体实例
StaticLibrary get_static_library();