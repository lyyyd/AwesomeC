#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "fileLib.h"

// 文件操作
void fun_init () {
  printf("09.file lib .eg \n");
}

FILELIB_API FileLib FileLib_Init() {
    FileLib lib;
	lib.init = fun_init;
    return lib;
}
