#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "cTypeLib.h"

// 数据类型
void c_type_init () {
  printf("02.c type lib .eg \n");
}

CTYPELIB_API CTypeLib CTypeLib_Init() {
    CTypeLib lib;
	lib.init = c_type_init;
    return lib;
}
