#ifndef COMPOSITETYPELIB_H
#define COMPOSITETYPELIB_H

#ifdef COMPOSITETYPELIB_EXPORTS
#define COMPOSITETYPELIB_API __declspec(dllexport)
#else
#define COMPOSITETYPELIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} CompositeTypeLib;

// 初始化动态库结构体
COMPOSITETYPELIB_API CompositeTypeLib CompositeTypeLib_Init();

#endif