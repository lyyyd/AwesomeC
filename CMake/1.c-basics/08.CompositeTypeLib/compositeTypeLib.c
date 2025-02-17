#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "compositeTypeLib.h"

// 复合类型
void composite_type_init () {
  printf("08.composite type lib .eg \n");
}

COMPOSITETYPELIB_API CompositeTypeLib CompositeTypeLib_Init() {
    CompositeTypeLib lib;
	lib.init = composite_type_init;
    return lib;
}
