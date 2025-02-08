//#pragma once
//#ifdef DYNAMICLIBRARY_EXPORTS
//#define DYNAMICLIBRARY_API __declspec(dllexport)
//#else
//#define DYNAMICLIBRARY_API __declspec(dllimport)
//#endif
//
//// 声明 add 函数
//DYNAMICLIBRARY_API int add(int a, int b);

// dynamicLibrary.h
#ifdef DYNAMICLIBRARY_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

// 定义动态库函数封装结构体
typedef struct {
    int (*add)(int a, int b);
} DynamicLibrary;

// 获取动态库函数封装结构体实例
DYNAMICLIBRARY_API DynamicLibrary get_dynamic_library();