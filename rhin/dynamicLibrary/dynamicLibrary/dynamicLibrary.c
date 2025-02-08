//#include "dynamicLibrary.h"
//
//// 实现 add 函数
//DYNAMICLIBRARY_API int add(int a, int b) {
//    return a + b;
//}


#include "dynamicLibrary.h"

// 动态库的 add 函数实现
static int dynamic_add(int a, int b) {
    return a + b;
}

// 获取动态库函数封装结构体实例
DYNAMICLIBRARY_API DynamicLibrary get_dynamic_library() {
    DynamicLibrary lib;
    lib.add = dynamic_add;
    return lib;
}