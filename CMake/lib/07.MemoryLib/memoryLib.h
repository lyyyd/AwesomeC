#ifndef MEMORYLIB_H
#define MEMORYLIB_H

#ifdef MEMORYLIB_EXPORTS
#define MEMORYLIB_API __declspec(dllexport)
#else
#define MEMORYLIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} MemoryLib;

// 初始化动态库结构体
MEMORYLIB_API MemoryLib MemoryLib_Init();

#endif