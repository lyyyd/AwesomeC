#ifndef CTYPELIB_H
#define CTYPELIB_H

#ifdef CTYPELIB_EXPORTS
#define CTYPELIB_API __declspec(dllexport)
#else
#define CTYPELIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} CTypeLib;

// 初始化动态库结构体
CTYPELIB_API CTypeLib CTypeLib_Init();

#endif