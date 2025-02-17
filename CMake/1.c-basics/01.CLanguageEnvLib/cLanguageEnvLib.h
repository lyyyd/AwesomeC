#ifndef CLANGUAGEENVLIB_H
#define CLANGUAGEENVLIB_H

#ifdef CLANGUAGEENVLIB_EXPORTS
#define CLANGUAGEENVLIB_API __declspec(dllexport)
#else
#define CLANGUAGEENVLIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} CLanguageEnvLib;

// 初始化动态库结构体
CLANGUAGEENVLIB_API CLanguageEnvLib CLanguageEnvLib_Init();

#endif