//
// Created by Toby Dragon on 9/11/18.
//
#include <iostream>
#include "TestLib.h"
#include "ArrayLib.h"

void toStringTest   (){
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
    int unusedTimer=0;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (i != find(a1, 10, a1[i], unusedTimer)){
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
    printAssertEquals(2, find(a2, 10, 3, unusedTimer));
    printAssertEquals(-1, find(a2, 10, 500, unusedTimer));
    printAssertEquals(-1, find(a2, 0, 10, unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void findLastTest(){
    std::cout << "-------findLastTest---------" <<std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    int unusedTimer=0;
    for (int i=0; i< 10; i++){
        if (i != findLast(a1, 10, a1[i], unusedTimer)){
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
    printAssertEquals(8, findLast(a2, 10, 3, unusedTimer));
    printAssertEquals(-1, findLast(a2, 10, 500, unusedTimer));
    printAssertEquals(-1, findLast(a2, 0, 10, unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void findMaxIndexTest(){
    std::cout << "-------findMaxIndexTest---------" <<std::endl;
    int unusedTimer=0;
    int a1[]={3, 2, 5, 12, 16, 10};
    printAssertEquals(0, findMaxIndex(a1, 1, unusedTimer));
    printAssertEquals(0, findMaxIndex(a1, 2, unusedTimer));
    printAssertEquals(2, findMaxIndex(a1, 3, unusedTimer));
    printAssertEquals(4, findMaxIndex(a1, 6, unusedTimer));
    std::cout << "negatives:"<< std::endl;
    int a2[]={-300000, -200000, -500000, -1200000, -1600000, -1000000};
    printAssertEquals(0, findMaxIndex(a2, 1, unusedTimer));
    printAssertEquals(1, findMaxIndex(a2, 2, unusedTimer));
    printAssertEquals(1, findMaxIndex(a2, 3, unusedTimer));
    printAssertEquals(1, findMaxIndex(a2, 6, unusedTimer));
    std::cout << "Multiple occurrences of max:"<< std::endl;
    int a3[]={3, 2, 5, 1, 5, 1};
    printAssertEquals(2, findMaxIndex(a3, 6, unusedTimer));
    //expect an exception to be thrown when size < 1
    std::cout << "Throws exception:"<< std::endl;
    try{
        int* myPtr;
        findMaxIndex(myPtr, 0, unusedTimer);
        std::cout << "FAIL: find maxIndex did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        printAssertEquals("Array size must be > 0", e.what());
    }
    std::cout << "--done--" <<std::endl;
}

void binSearchTest(int* a, int size, int* notInVals, int sizeNotIn){
    bool allGood = true;
    int unusedTimer=0;
    for (int i=0; i<size; i++){
        int answer = binFind(a, size, a[i], unusedTimer);
        if ( answer != i){
            std::cout << "FAIL: Did not find " << a[i] << " in " << toString(a, size) << ", got: " << answer <<  std::endl;
            allGood = false;
        }
    }
    for (int i=0; i<sizeNotIn; i++){
        int ans = binFind(a, size, notInVals[i], unusedTimer);
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
    std::cout << "-------binSearchTest---------" <<std::endl;
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
    int unusedTimer=0;
    std::cout << "11 - array size 0\n";
    printAssertEquals(-1, binFind(a9, 0, 100, unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void countOccurrencesTest(){
    std::cout << "-------countOccurrencesTest---------" <<std::endl;
    int unusedTimer=0;
    //all ones
    int a1[] = {1, -2, 3, 22, 64, 33, 24, 0, 865, 23};
    for (int i=0; i<10; i++){
        printAssertEquals(1, countOccurrences(a1, 10, a1[i], unusedTimer));
    }
    //check not there
    printAssertEquals(0, countOccurrences(a1, 10, 4, unusedTimer));
    printAssertEquals(0, countOccurrences(a1, 10, -5, unusedTimer));


    int a2[] = {1, 2, 3, 22, 22, 33, 22, 9, 865, 1};
    printAssertEquals(0, countOccurrences(a2, 10, 0, unusedTimer));
    printAssertEquals(2, countOccurrences(a2, 10, 1, unusedTimer));
    printAssertEquals(3, countOccurrences(a2, 10, 22, unusedTimer));
    printAssertEquals(2, countOccurrences(a2, 5, 22, unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void copyArrayTest(){
    std::cout << "-------copyArrayTest---------" <<std::endl;
    int a1[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a2[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a3[] = {10, 20, 30, 220, 640, 330, 240, 90, 8650, 230};

    int unusedTimer=0;
    int* copy = copyArray(a1, 10, unusedTimer);
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

void mergeTest() {
    std::cout << "-------mergeTest---------" <<std::endl;
    int timer = 0;

    int a4[] {1, 5, 7, 9};

    int a6[] {2, 4, 6};
    int a7[] {1, 2, 4, 5, 6, 7, 9};
    std::cout << "Basic arrays:\n";
    int* a8 = merge(a4, 4, a6, 3, timer);
    printAssertArrayEqual(a7, a8, 7);
    delete[] a8;

    int a9[] {-100, -10, -1};
    int a10[] {-50, -15, -5};
    int a11[] {-100, -50, -15, -10, -5, -1};
    std::cout << "Negative numbers:\n";
    int* a12 = merge(a9, 3, a10, 3, timer);
    printAssertArrayEqual(a11, a12, 6);
    delete[] a12;

    int a1[] {};
    int a2[] {};
    std::cout << "Two empty arrays:\n";
    int* a3 = merge(a1, 0, a2, 0, timer);
    if (a3 == nullptr) {
        std::cout << "pass\n";
    } else {
        std::cout << "Fail: array " << a3 << std::endl;
    }
    delete[] a3;

    std::cout << "One empty and one full:\n";
    int* a5 = merge(a1, 0, a4, 4, timer);
    //test parameters in different order
    printAssertArrayEqual(a4, a5, 4);
    printAssertArrayEqual(a5, a4, 4);
    delete[] a5;
    std::cout << "--done--" <<std::endl;
}
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
        int num = genRandInt(low, high, unusedTimer);

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
    printAssertEquals(0, genRandInt(0, 0, unusedTimer));
    printAssertEquals(1, genRandInt(1, 1, unusedTimer));
    printAssertEquals(10, genRandInt(10, 10, unusedTimer));
    printAssertEquals(-1, genRandInt(-1, -1, unusedTimer));
    std::cout << "--done--" <<std::endl;
}

void genRandArrayTest(int low, int high){
    int countSize = high-low+1;
    int* randCounts = new int [countSize]{};
    int outCount=0;

    int unusedTimer=0;
    int* randArray = genRandArray(countSize*100, low, high, unusedTimer);
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
    int* rands = genRandArray(15, 20, 25, unusedTimer);
    std::cout << "20 to 25:" << std::endl;
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = genRandArray(15, -3, 3, unusedTimer);
    std::cout << "-3 to 3:" << std::endl;
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = nullptr;

    genRandArrayTest(0, 10);
    genRandArrayTest(1, 5);
    genRandArrayTest(50, 60);
    genRandArrayTest(-10, 10);
    genRandArrayTest(-10, -5);
    std::cout << "--done--" <<std::endl;
}

bool checkSorted(int* a, int size){
    int failCount = 0;
    for (int i=0; i<size-1; i++){
        if (a[i] > a[i+1]) {
            failCount++;
        }
    }
    return failCount == 0;
}

//Note: this relies on working countOccurrences
bool checkSameElements(int* a1, int* a2, int size){
    int unusedTimer=0;
    for (int i=0; i<size; i++){
        if (countOccurrences(a1, size, a1[i], unusedTimer) != countOccurrences(a2, size, a1[i], unusedTimer)){
            return false;
        }
    }
    return true;
}

//Note: this relies on working genRandArray, copyArray, and countOccurrences
void sortTest(){
    std::cout << "-------sortTest---------" <<std::endl;
    int unusedTimer=0;
    for (int i=1; i<20; i++){
        int* orig = genRandArray(i, 0, i, unusedTimer);
        int* sortArray = copyArray(orig, i, unusedTimer);
        sort(sortArray, i, unusedTimer);
        std::cout << "size:" << i<< std::endl;
        printAssertEquals(true, checkSorted(sortArray, i));
        printAssertEquals(true, checkSameElements(sortArray, orig, i));
        delete[] orig;
        orig = nullptr;
        delete[] sortArray;
        sortArray = nullptr;
    }
    std::cout << "--done--" <<std::endl;
}

//Note: this relies on working genRandArray, copyArray, and countOccurrences
void mergeSortTest(){
    std::cout << "-------mergeSortTest---------" <<std::endl;
    int unusedTimer=0;
    for (int i=1; i<20; i++){
        int* orig = genRandArray(i, 0, i, unusedTimer);
        int* sortArray = mergeSort(orig, i, unusedTimer);
        std::cout << "size:" << i << std::endl;
        printAssertEquals(true, checkSorted(sortArray, i));
        printAssertEquals(true, checkSameElements(sortArray, orig, i));
        delete[] orig;
        orig = nullptr;
        delete[] sortArray;
        sortArray = nullptr;
    }
    std::cout << "--done--" <<std::endl;
}

//relies on a working find
void genShuffledArrayTest(int size) {
    int unusedTimer=0;
    int *shuffled = genShuffledArray(size, unusedTimer);
    int missing = 0;
    for (int i = 1; i <= size; i++) {
        if (find(shuffled, size, i, unusedTimer) == -1) {
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
    int* shuffled = genShuffledArray(10, unusedTimer);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = genShuffledArray(10, unusedTimer);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = nullptr;

    genShuffledArrayTest(12);
    genShuffledArrayTest(5);
    genShuffledArrayTest(1);
    int* array = genShuffledArray(0, unusedTimer);
    if (array == nullptr){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, array:" << array << std::endl;
    }
    std::cout << "--done--" <<std::endl;
}

int main(){
    srand(time(NULL));

    findTest();
    findLastTest();
    findMaxIndexTest();
    toStringTest();
    countOccurrencesTest();

    copyArrayTest();
    mergeTest();
    binSearchTest();

    genRandIntTest();
    genRandArrayTest();

    //Note: these rely on working genRandArray(), copyArray(), and countOccurrences()
    sortTest();
    mergeSortTest();

    //Note: this relies on working find()
    genShuffledArrayTest();

    return 0;
}


