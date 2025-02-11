#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "memoryLib.h"

// 内存管理
void memory_init () {
  printf("07.memory lib .eg \n");
}

MEMORYLIB_API MemoryLib MemoryLib_Init() {
    MemoryLib lib;
	lib.init = memory_init;
    return lib;
}
