//
// Created by Toby Dragon on 9/4/18.
//
#include <iostream>
#include "TestLibrary.h"

void printAssertEquals(int expected, int actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertEquals(bool expected, bool actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << std::boolalpha;//？？
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}