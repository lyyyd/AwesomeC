#ifndef STATEMENTSLIB_H
#define STATEMENTSLIB_H

#ifdef STATEMENTSLIB_EXPORTS
#define STATEMENTSLIB_API __declspec(dllexport)
#else
#define STATEMENTSLIB_API __declspec(dllimport)
#endif

typedef struct {
    void (*init)();
} StatementsLib;

// 初始化动态库结构体
STATEMENTSLIB_API StatementsLib StatementsLib_Init();

#endif