//#include "staticLibrary.h"
//
//int add(int a, int b) {
//    return a + b;
//}

#include "staticLibrary.h"

int static_add(int a, int b) {
    return a + b;
}

StaticLibrary StaticLibrary_Init() {
    StaticLibrary lib;
    lib.add = static_add;
    return lib;
}