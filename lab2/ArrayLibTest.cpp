//
// Created by Toby Dragon on 9/11/18.
//
#include <iostream>
#include "TestLib.h"
#include "ArrayLib.h"


void genRandIntTest(){
    std::cout << "-------genRandIntTest---------" <<std::endl;
    //TODO
    int num = 0;
    std::cout << "test min1 < max10: ";
    num = genRandInt(1,10);
    if (num<=10&&num>=1){
        std::cout<<"true"<<std::endl;
    }
    else{
        std::cout<<"false"<<std::endl;
    }

    std::cout << "test min20 > max10: ";
    num = genRandInt(20,10);
    if (num<=20&&num>=10){
        std::cout<<"true"<<std::endl;
    }
    else{
        std::cout<<"false"<<std::endl;
    }

    std::cout << "--done--" <<std::endl;


}

void genRandArrayTest() {
    std::cout << "-------genRandArrayTest---------" <<std::endl;
    //TODO: ensure it works properly, and ensure that there aren't memory leaks or dangling pointers in your test
    std::cout << "test min1 > max10: ";
    std::string result = toString(genRandArray(5,1,10),5);
    std::cout << result <<std::endl;
    std::cout << "test min20 > max10: ";
    result = toString(genRandArray(5,20,10),5);
    std::cout << result <<std::endl;
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

void findTest(){
    std::cout << "-------findTest---------" <<std::endl;
    //TODO: Be sure you get correct answers with:
    // values at either end, and in the middle range
    // positive, negative, 0, values
    // values that are not present
    // when multiple of the value occurs in the array
    // when size is < 1
    int array1[]={1,3,0,7,4,3,6,4,3,-5,100};
    std::cout << "test first value: ";
    printAssertEquals(find(array1,11,1),0);
    std::cout << "test last value: ";
    printAssertEquals(find(array1,11,100),10);
    std::cout << "test meddle value: ";
    printAssertEquals(find(array1,11,4),4);
    std::cout << "test negative value: ";
    printAssertEquals(find(array1,11,-5),9);
    std::cout << "test 0 value: ";
    printAssertEquals(find(array1,11,0),2);
    std::cout << "test not present value: ";
    printAssertEquals(find(array1,11,101),-1);
    std::cout << "test multiple value: ";
    printAssertEquals(find(array1,11,3),1);
    std::cout << "test size 0: ";
    printAssertEquals(find(array1,0,3),-1);
    std::cout << "--done--" <<std::endl;
}

void findLastTest(){
    std::cout << "-------findLastTest---------" <<std::endl;
    //TODO
    int array2[]={4,5,2,8,-1,46,-4,4,3,5,23,0};
    std::cout << "test first value: ";
    printAssertEquals(findLast(array2,11,2),2);
    std::cout << "test last value: ";
    printAssertEquals(findLast(array2,11,23),10);
    std::cout << "test meddle value: ";
    printAssertEquals(findLast(array2,11,-4),6);
    std::cout << "test negative value: ";
    printAssertEquals(findLast(array2,11,-1),4);
    std::cout << "test 0 value: ";
    printAssertEquals(findLast(array2,11,0),11);
    std::cout << "test not present value: ";
    printAssertEquals(findLast(array2,11,101),-1);
    std::cout << "test multiple value: ";
    printAssertEquals(findLast(array2,11,5),9);
    std::cout << "test size 0: ";
    printAssertEquals(findLast(array2,0,3),-1);
    std::cout << "--done--" <<std::endl;
}

void findMaxIndexTest(){
    std::cout << "-------findMaxIndexTest---------" <<std::endl;
    //TODO: testing for normal cases of findMax index
    int array1[]={-4,-1,4,0,6,2,7,3,-6,-1,10};
    std::cout << "test include negative and zero value: ";
    printAssertEquals(findMaxIndex(array1,11),10);
    int array2[]={-4,-1,-5,-11,-6,-2,-7,-3,-16,-14,-10};
    std::cout << "test all negative value: ";
    printAssertEquals(findMaxIndex(array2,11),-1);
    int array3[]={4,1,5,11,6,2,7,3,16,14,10};
    std::cout << "test all positive value: ";
    printAssertEquals(findMaxIndex(array3,11),16);
    int array4[]={20,1,5,20,6,2,7,3,20,14,10};
    std::cout << "test many max value: ";
    printAssertEquals(findMaxIndex(array4,11),20);


    //expect an exception to be thrown when size < 1
    std::cout << "test exception: ";
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

void copyArrayTest(){
    std::cout << "-------copyArrayTest---------" <<std::endl;
    int a1[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a2[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a3[] = {10, 20, 30, 220, 640, 330, 240, 90, 8650, 230};

    int* copy = copyArray(a1, 10);

    //check that it is a good copy
    printAssertEquals(copy, a1, 10);
    //change the copy
    for (int i=0; i< 10; i++){
        copy[i] = copy[i]*10;
    }


    //check that the copy is changed
    printAssertEquals(copy, a3, 10);
    //check that the original is unchanged
    printAssertEquals(a1, a2, 10);

    delete[] copy;
    copy = nullptr;
    std::cout << "--done--" <<std::endl;
}

//relies on a working find function!!!
void genShuffledArrayTest(int size) {
    int linesRun = 0;
    int *shuffled = genShuffledArray(size);
    int missing = 0;
    for (int i = 1; i <= size; i++) {
        if (find(shuffled, size, i) == -1) {
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
    int* shuffled = genShuffledArray(10);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = genShuffledArray(10);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = nullptr;

    //relies on a working find function (see above)
    genShuffledArrayTest(12);
    genShuffledArrayTest(5);
    genShuffledArrayTest(1);
    int* array = genShuffledArray(0);
    if (array == nullptr){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, array:" << array << std::endl;
    }
    std::cout << "--done--" <<std::endl;
}

int main(){

    genRandIntTest();
    genRandArrayTest();
    toStringTest();
    findTest();
    findLastTest();
    findMaxIndexTest();
    copyArrayTest();
    genShuffledArrayTest();

    return 0;
}


