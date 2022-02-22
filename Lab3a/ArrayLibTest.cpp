//
// Created by Toby Dragon on 9/11/18.
//
#include <iostream>
#include "TestLib.h"
#include "ArrayLib.h"


void genRandIntTest(int low, int high){
    std::cout << low << " and " << high << ":\t" ;
    int countSize;
    if (high >= low){
        countSize = high-low+1;
    }
    else {
        countSize = low-high+1;
    }
    int* randCounts = new int [countSize]{};

    int outCount=0;

    for (int i=0; i<countSize*100; i++){
        int unusedTimer=0;
        int num = genRandInt(low, high, &unusedTimer);

        if (high >= low){
            num = num - low;
        }
        else {
            num = num - high;
        }
        if (num >= countSize){
            outCount++;
        }
        else {
            randCounts[num]++;
        }
    }

    bool allPresent = true;
    for (int i=0; i<countSize; i++){
        if (randCounts[i]<=0){
            allPresent = false;
        }
    }
    delete[] randCounts;
    randCounts = nullptr;

    if (allPresent && outCount == 0){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << std::boolalpha << "FAIL, allPresent:" << allPresent << ", outCount:" << outCount << std::endl;
    }
}

void genRandIntTest(){
    std::cout << "-------genRandIntTest---------" <<std::endl;
    genRandIntTest(1, 6);
    genRandIntTest(5, 9);
    genRandIntTest(-30, -26);
    genRandIntTest(-3, 3);
    genRandIntTest(6, 1);

    std::cout << "Testing generating a single value:" << std::endl;
    int unusedTimer=0;
    printAssertEquals(0, genRandInt(0, 0, &unusedTimer));
    printAssertEquals(1, genRandInt(1, 1, &unusedTimer));
    printAssertEquals(10, genRandInt(10, 10, &unusedTimer));
    printAssertEquals(-1, genRandInt(-1, -1, &unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void genRandArrayTest(int low, int high){
    int countSize = high-low+1;
    int* randCounts = new int [countSize]{};
    int outCount=0;

    int unusedTimer=0;
    int* randArray = genRandArray(countSize*100, low, high, &unusedTimer);
    for (int i=0; i<countSize*100; i++){
        int num = randArray[i];
        num = num - low;
        if (num >= countSize){
            outCount++;
        }
        else {
            randCounts[num]++;
        }
    }
    delete[] randArray;
    randArray = nullptr;

    bool allPresent = true;
    for (int i=0; i<countSize; i++){
        if (randCounts[i]<=0){
            allPresent = false;
        }
    }
    delete[] randCounts;
    randCounts = nullptr;

    if (allPresent && outCount == 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, allPresent:" << allPresent << ", outCount:" << outCount << std::endl;
    }
}

void genRandArrayTest(){
    std::cout << "-------genRandArrayTest---------" <<std::endl;
    //print some random arrays to make sure they look right
    int unusedTimer=0;
    int* rands = genRandArray(15, 20, 25, &unusedTimer);
    std::cout << "20 to 25:" << std::endl;
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = genRandArray(15, -3, 3, &unusedTimer);
    std::cout << "-3 to 3:" << std::endl;
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = nullptr;

    genRandArrayTest(0, 10);
    genRandArrayTest(1, 5);
    genRandArrayTest(50, 60);
    genRandArrayTest(-10, 10);
    genRandArrayTest(-10, -5);
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

void findTest(){
    std::cout << "-------findTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    int unusedTimer=0;
    for (int i=0; i< 10; i++){
        if (i != find(a1, 10, a1[i], &unusedTimer)){
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
    printAssertEquals(2, find(a2, 10, 3, &unusedTimer));
    printAssertEquals(-1, find(a2, 10, 500, &unusedTimer));
    printAssertEquals(-1, find(a2, 0, 10, &unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void findLastTest(){
    std::cout << "-------findLastTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    int unusedTimer=0;
    for (int i=0; i< 10; i++){
        if (i != findLast(a1, 10, a1[i], &unusedTimer)){
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
    printAssertEquals(8, findLast(a2, 10, 3, &unusedTimer));
    printAssertEquals(-1, findLast(a2, 10, 500, &unusedTimer));
    printAssertEquals(-1, findLast(a2, 0, 10, &unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void findMaxIndexTest(){
    std::cout << "-------findMaxIndexTest---------" <<std::endl;
    int a1[]={3, 2, 5, 12, 16, 10};
    int unusedTimer=0;
    printAssertEquals(0, findMaxIndex(a1, 1, &unusedTimer));
    printAssertEquals(0, findMaxIndex(a1, 2, &unusedTimer));
    printAssertEquals(2, findMaxIndex(a1, 3, &unusedTimer));
    printAssertEquals(4, findMaxIndex(a1, 6, &unusedTimer));
    std::cout << "negatives:"<< std::endl;
    int a2[]={-300000, -200000, -500000, -1200000, -1600000, -1000000};
    printAssertEquals(0, findMaxIndex(a2, 1, &unusedTimer));
    printAssertEquals(1, findMaxIndex(a2, 2, &unusedTimer));
    printAssertEquals(1, findMaxIndex(a2, 3, &unusedTimer));
    printAssertEquals(1, findMaxIndex(a2, 6, &unusedTimer));
    std::cout << "Multiple occurrences of max:"<< std::endl;
    int a3[]={3, 2, 5, 1, 5, 1};
    printAssertEquals(2, findMaxIndex(a3, 6, &unusedTimer));
    //expect an exception to be thrown when size < 1
    std::cout << "Throws exception:"<< std::endl;
    try{
        int* myPtr;
        findMaxIndex(myPtr, 0, &unusedTimer);
        std::cout << "FAIL: find maxIndex did not throw exception";
    }
    catch(std::invalid_argument& e){
        printAssertEquals("Array size must be > 0", e.what());
    }
    std::cout << "--done--" <<std::endl;
}

void copyArrayTest(){
    std::cout << "-------copyArrayTest---------" <<std::endl;
    int a1[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a2[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a3[] = {10, 20, 30, 220, 640, 330, 240, 90, 8650, 230};

    int unusedTimer=0;
    int* copy = copyArray(a1, 10, &unusedTimer);
    printAssertEquals(copy, a1, 10);
    for (int i=0; i< 10; i++){
        copy[i] = copy[i]*10;
    }
    printAssertEquals(copy, a3, 10);
    printAssertEquals(a1, a2, 10);

    delete[] copy;
    copy = nullptr;
    std::cout << "--done--" <<std::endl;
}

//relies on a working find function!!!
void genShuffledArrayTest(int size) {
    int unusedTimer=0;
    int *shuffled = genShuffledArray(size, &unusedTimer);
    int missing = 0;
    for (int i = 1; i <= size; i++) {
        if (find(shuffled, size, i, &unusedTimer) == -1) {
            missing++;
        }
    }
    delete[] shuffled;
    shuffled = nullptr;
    if (missing <= 0) {
        std::cout << "pass\n";
    } else {
        std::cout << "FAIL, missing count:" << missing << std::endl;
    }
}

void genShuffledArrayTest(){
    std::cout << "-------genShuffledArrayTest---------" <<std::endl;
    //print some shuffled arrays to make sure they look right
    int unusedTimer=0;
    int* shuffled = genShuffledArray(10, &unusedTimer);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = genShuffledArray(10, &unusedTimer);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = nullptr;

    genShuffledArrayTest(12);
    genShuffledArrayTest(5);
    genShuffledArrayTest(1);
    int* array = genShuffledArray(0, &unusedTimer);
    if (array == nullptr){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, array:" << array << std::endl;
    }
    std::cout << "--done--" <<std::endl;
}

void countOccurencesTest(){
    //TODO
    std::cout << "-------countOccurencesTest---------" <<std::endl;
    int unusedTimer=0;
    std::cout << "appear 1 times: ";
    int test1[]={1,3,5,7,9,10};
    printAssertEquals(1, countOccurrences(test1,6,9,&unusedTimer));
    std::cout << "appear multiple times: ";
    int test2[]={1,6,3,9,3,9,3,3,3};
    printAssertEquals(5, countOccurrences(test2,9,3,&unusedTimer));
    std::cout << "negative: ";
    int test3[]={-1,-7,-5,-7,-7,-9,-10};
    printAssertEquals(3, countOccurrences(test3,7,-7,&unusedTimer));
    std::cout << "Zeros: ";
    int test4[]={1,0,-1,3,0,0,5,7,9,0,0,10};
    printAssertEquals(5, countOccurrences(test4,12,0,&unusedTimer));
    std::cout << "appear 0 times: ";
    int test5[]={1,3,5,7,9,10};
    printAssertEquals(0, countOccurrences(test5,6,33,&unusedTimer));

    std::cout << "--done--" <<std::endl;

}

void sortTest(){
    // TODO: Write a thorough test of sort. Sort several arrays, and write code to check:
    std::cout << "-------sortTest---------" <<std::endl;
    int unusedTimer=0;
    std::cout << "min to max: ";
    int test1[]={1,3,5,7,9,10};
    sort(test1,6,&unusedTimer);
    printAssertEquals("{1, 3, 5, 7, 9, 10}",toString(test1,6));
    std::cout << "max to min: ";
    int test2[]={20,10,9,8,5,2,1};
    sort(test2,7,&unusedTimer);
    printAssertEquals("{1, 2, 5, 8, 9, 10, 20}",toString(test2,7));
    std::cout << "random list: ";
    int test3[]={14,74,234,76,32,97,4,2};
    sort(test3,8,&unusedTimer);
    printAssertEquals("{2, 4, 14, 32, 74, 76, 97, 234}",toString(test3,8));
    std::cout << "a num appear more than 1 times: ";
    int test4[]={3,6,7,2,6,7,1};
    sort(test4,7,&unusedTimer);
    printAssertEquals("{1, 2, 3, 6, 6, 7, 7}",toString(test4,7));
    std::cout << "zeros: ";
    int test5[]={3,6,0,2,6,7,0};
    sort(test5,7,&unusedTimer);
    printAssertEquals("{0, 0, 2, 3, 6, 6, 7}",toString(test5,7));
    std::cout << "negatives: ";
    int test6[]={-3,-6,0,-2,-6,-7,-33};
    sort(test6,7,&unusedTimer);
    printAssertEquals("{-33, -7, -6, -6, -3, -2, 0}",toString(test6,7));
    // the numbers after sorting are actually in increasing order
    // the same set of values is present after being sorted (hint: you can use countOccurrences)
    std::cout << "--done--" <<std::endl;
}

int main(){
    srand(time(NULL));

    genRandIntTest();
    genRandArrayTest();
    toStringTest();
    findTest();
    findLastTest();
    findMaxIndexTest();
    copyArrayTest();
    genShuffledArrayTest();

    countOccurencesTest();
    sortTest();

    return 0;
}


