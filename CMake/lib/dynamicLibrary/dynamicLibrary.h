#ifndef DYNAMICLIBRARY_H
#define DYNAMICLIBRARY_H

#ifdef DYNAMICLIBRARY_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

typedef struct {
    int (*add)(int a, int b);
} DynamicLibrary;

// 初始化动态库结构体
DYNAMICLIBRARY_API DynamicLibrary DynamicLibrary_Init();

#endif

//#ifndef DYNAMICLIBRARY_H
//#define DYNAMICLIBRARY_H
//
//#ifdef DYNAMICLIBRARY_EXPORTS
//#define DYNAMICLIBRARY_API __declspec(dllexport)
//#else
//#define DYNAMICLIBRARY_API __declspec(dllimport)
//#endif
//
//DYNAMICLIBRARY_API int add(int a, int b);
//
//#endif
