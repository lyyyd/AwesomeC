#ifndef ARRLIB_H
#define ARRLIB_H

#ifdef ARRLIB_EXPORTS
#define ARRLIB_API __declspec(dllexport)
#else
#define ARRLIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} ArrLib;

// 初始化动态库结构体
ARRLIB_API ArrLib ArrLib_Init();

#endif