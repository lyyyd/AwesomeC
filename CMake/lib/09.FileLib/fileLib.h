#ifndef FILELIB_H
#define FILELIB_H

#ifdef FILELIB_EXPORTS
#define FILELIB_API __declspec(dllexport)
#else
#define FILELIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} FileLib;

// 初始化动态库结构体
FILELIB_API FileLib FileLib_Init();

#endif