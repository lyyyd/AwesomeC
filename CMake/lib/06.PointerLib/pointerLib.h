#ifndef POINTERLIB_H
#define POINTERLIB_H

#ifdef POINTERLIB_EXPORTS
#define POINTERLIB_API __declspec(dllexport)
#else
#define POINTERLIB_API __declspec(dllimport)
#endif

typedef struct {
    int (*add)(int a, int b);
    int (*sub)(int a, int b);
    void (*init)();
} PointerLib;

// 初始化动态库结构体
POINTERLIB_API PointerLib PointerLib_Init();

#endif