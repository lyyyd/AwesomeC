//
//#ifndef STATICLIBRARY_H
//#define STATICLIBRARY_H
//
//int add(int a, int b);
//
//#endif


#ifndef STATICLIBRARY_H
#define STATICLIBRARY_H

typedef struct {
    int (*add)(int a, int b);
} StaticLibrary;

// 初始化静态库结构体
StaticLibrary StaticLibrary_Init();

#endif