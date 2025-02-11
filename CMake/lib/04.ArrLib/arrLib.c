#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "arrLib.h"

// 数组
void array_init () {
  printf("04.array lib .eg \n");
}

ARRLIB_API ArrLib ArrLib_Init() {
    ArrLib lib;
	lib.init = array_init;
    return lib;
}
