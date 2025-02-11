#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "funLib.h"

// 函数
void fun_init () {
  printf("05.fun lib .eg \n");
}

FUNLIB_API FunLib FunLib_Init() {
    FunLib lib;
	lib.init = fun_init;
    return lib;
}
