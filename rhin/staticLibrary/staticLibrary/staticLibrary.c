//// staticLibrary.c
//#include "staticLibrary.h"
//
//// 实现 add 函数
//int add(int a, int b) {
//    return a + b;
//}

#include "staticLibrary.h"

// 静态库的 add 函数实现
static int static_add(int a, int b) {
    return a + b;
}

// 获取静态库函数封装结构体实例
StaticLibrary get_static_library() {
    StaticLibrary lib;
    lib.add = static_add;
    return lib;
}