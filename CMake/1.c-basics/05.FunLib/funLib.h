#ifndef FUNLIB_H
#define FUNLIB_H

#ifdef FUNLIB_EXPORTS
#define FUNLIB_API __declspec(dllexport)
#else
#define FUNLIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} FunLib;

// 初始化动态库结构体
FUNLIB_API FunLib FunLib_Init();

#endif