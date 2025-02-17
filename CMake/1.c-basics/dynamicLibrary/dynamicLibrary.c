#include "dynamicLibrary.h"

int dynamic_add(int a, int b) {
    return a + b;
}

DYNAMICLIBRARY_API DynamicLibrary DynamicLibrary_Init() {
    DynamicLibrary lib;
    lib.add = dynamic_add;
    return lib;
}

//#include "dynamicLibrary.h"
//
//DYNAMICLIBRARY_API int add(int a, int b) {
//    return a + b;
//}