//
// Created by Toby Dragon on 9/4/18.
//  Updated by Mariama Diallo 12/6/19
//
#include <iostream>
#include "TestLib.h"
#include <cmath>
#include <limits>

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
        std::cout << std::boolalpha;
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertEquals(std::string expected, std::string actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}
bool printAssertEquals(double expected, double actual, double epsilon){
    if(std::abs(expected - actual) < epsilon){
        std::cout << "pass" << std::endl;
        return true ;

    }
    else{
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
        return false;
    }


}

void printAssertEquals(int* a1, int *a2, int size){
    int failCount = 0;
    for (int i=0; i<size; i++){
        if (a1[i] != a2[i]) {
            failCount++;
        }
    }
    if (failCount <=0){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, failCount: " << failCount << std::endl;
    }
}

void printAssertArrayEqual(int* a1, int *a2, int size){
    int failCount = 0;
    for (int i=0; i<size; i++){
        if (a1[i] != a2[i]) {
            failCount++;
        }
    }
    if (failCount <=0){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, failCount: " << failCount << std::endl;
    }
}
