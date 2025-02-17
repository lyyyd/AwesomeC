#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "cLanguageEnvLib.h"

// C环境
void c_language_env_init () {
	printf("01.c language env lib .eg \n");
}

CLANGUAGEENVLIB_API CLanguageEnvLib CLanguageEnvLib_Init() {
    CLanguageEnvLib lib;
	lib.init = c_language_env_init;
    return lib;
}
