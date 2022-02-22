
#include <iostream>
#include "TestLib.h"
#include "ArrayLibRec.h"

void findTest(){
    std::cout << "-------findTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (i != find(a1, 10, a1[i])){
            failCount++;
        }
    }
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }

    int a2[]={10, 20, 3, 22, 2, 33, 3, 9, 3, 2};
    printAssertEquals(2, find(a2, 10, 3));
    printAssertEquals(-1, find(a2, 10, 500));
    printAssertEquals(-1, find(a2, 0, 10));
    std::cout << "--done--" <<std::endl;
}

void findLastTest(){
    std::cout << "-------findLastTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    int unusedTimer=0;
    for (int i=0; i< 10; i++){
        if (i != findLast(a1, 10, a1[i])){
            failCount++;
        }
    }
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }

    int a2[]={10, 20, 3, 22, 2, 33, 3, 9, 3, 2};
    printAssertEquals(8, findLast(a2, 10, 3));
    printAssertEquals(-1, findLast(a2, 10, 500));
    printAssertEquals(-1, findLast(a2, 0, 10));
    std::cout << "--done--" <<std::endl;
}

void findMaxIndexTest(){
    std::cout << "-------findMaxIndexTest---------" <<std::endl;
    int a1[]={3, 2, 5, 12, 16, 10};
    printAssertEquals(0, findMaxIndex(a1, 1));
    printAssertEquals(0, findMaxIndex(a1, 2));
    printAssertEquals(2, findMaxIndex(a1, 3));
    printAssertEquals(4, findMaxIndex(a1, 6));
    std::cout << "negatives:"<< std::endl;
    int a2[]={-300000, -200000, -500000, -1200000, -1600000, -1000000};
    printAssertEquals(0, findMaxIndex(a2, 1));
    printAssertEquals(1, findMaxIndex(a2, 2));
    printAssertEquals(1, findMaxIndex(a2, 3));
    printAssertEquals(1, findMaxIndex(a2, 6));
    std::cout << "Multiple occurrences of max:"<< std::endl;
    int a3[]={3, 2, 5, 1, 5, 1};
    printAssertEquals(2, findMaxIndex(a3, 6));
    //expect an exception to be thrown when size < 1
    std::cout << "Throws exception:"<< std::endl;
    try{
        int* myPtr;
        findMaxIndex(myPtr, 0);
        std::cout << "FAIL: find maxIndex did not throw exception";
    }
    catch(std::invalid_argument& e){
        printAssertEquals("Array size must be > 0", e.what());
    }
    std::cout << "--done--" <<std::endl;
}

void toStringTest(){
    std::cout << "-------toStringTest---------" <<std::endl;
    int a1[] = {1, 2, 3, 4};
    printAssertEquals("{1, 2, 3, 4}", toString(a1, 4));
    int a2[] = {1};
    printAssertEquals("{1}", toString(a2, 1));
    int a3[] = {121, 432, 53, 4, -96, 0, 3684};
    printAssertEquals("{121, 432, 53, 4, -96, 0, 3684}", toString(a3, 7));
    printAssertEquals("{}", toString(a3, 0));
    std::cout << "--done--" <<std::endl;
}

void binSearchTest(int* a, int size, int* notInVals, int sizeNotIn){
    bool allGood = true;
    for (int i=0; i<size; i++){
        int answer = binFind(a, size, a[i]);
        if ( answer != i){
            std::cout << "FAIL: Did not find " << a[i] << " in " << toString(a, size) << ", got: " << answer <<  std::endl;
            allGood = false;
        }
    }
    for (int i=0; i<sizeNotIn; i++){
        int ans = binFind(a, size, notInVals[i]);
        if (ans != -1){
            std::cout << "FAIL: gave " << ans <<" instead of -1 for " << notInVals[i] << " in " << toString(a, size) << std::endl;
            allGood = false;
        }
    }
    if (allGood){
        std::cout << "pass" << std::endl;
    }
}

void binSearchTest(){
    //simplest case
    std::cout << "binSearchTest" << std::endl;
    int a1[] {5, 6, 7};
    int a2[] {2, 8, 10};
    std::cout << "1 - only  3 elements" <<  std::endl;
    binSearchTest(a1, 3, a2, 3);
    std::cout << "2 - only  3 elements" <<  std::endl;
    binSearchTest(a2, 3, a1, 3);
    
    //odd number of elements
    int a3[] {10, 20, 30, 40, 50, 60, 70};
    int a4[] {5, 15, 25, 35, 45, 55, 65, 75, 85};
    std::cout << "3 - odd number of elements" <<  std::endl;
    binSearchTest(a3, 7, a4, 9);
    std::cout << "4 - odd number of elements" <<  std::endl;
    binSearchTest(a4, 9, a3, 7);
    
    //even number of elements
    int a5[] {2, 5, 9, 11};
    int a6[] {0, 1, 3, 6, 10, 12, 22, 367};
    std::cout << "5 - even number of elements" <<  std::endl;
    binSearchTest(a5, 4, a6, 8);
    std::cout << "6 - even number of elements" <<  std::endl;
    binSearchTest(a6, 8, a5, 4);
    
    //test arrays with negative values
    int a7[] {-11, -10, -8, -5, -1};
    int a8[] {-400, -300, -200, -100, -99, -98};
    std::cout << "7 - negative values\n";
    binSearchTest(a7, 5, a8, 6);
    std::cout << "8 - negative values\n";
    binSearchTest(a8, 6, a7, 5);
    
    //test for arrays of size 1
    int a9[] {3};
    int a10[] {4};
    std::cout << "9 - size 1\n";
    binSearchTest(a9,1,a10,1);
    std::cout << "10 - size 1\n";
    binSearchTest(a10,1,a9,1);
    
    // and 0
    std::cout << "11 - array size 0\n";
    printAssertEquals(-1, binFind(a9, 0, 100));
    
}

int main(){
    findTest();
    findLastTest();
    findMaxIndexTest();
    toStringTest();
    binSearchTest();
   
    return 0;
}


