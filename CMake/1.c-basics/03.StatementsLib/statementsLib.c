#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "statementsLib.h"

// 各种控制语句
void statements_init () {
  printf("03.statements lib .eg \n");
}

STATEMENTSLIB_API StatementsLib StatementsLib_Init() {
    StatementsLib lib;
	lib.init = statements_init;
    return lib;
}
