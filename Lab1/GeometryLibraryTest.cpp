//
// Created by Toby Dragon on 9/4/18.
//
#include <iostream>
#include "GeometryLibrary.h"
#include "TestLibrary.h"

void testGreaterOf2(){
    std::cout << "-------testGreaterOf2---------" <<std::endl;
    std::cout << "Larger first:\t";
    printAssertEquals(5, greaterOf2(5, 2));
    std::cout << "Larger last:\t";
    printAssertEquals(9, greaterOf2(3, 9));
    std::cout << "Equal:\t";
    printAssertEquals(22, greaterOf2(22, 22));
    std::cout << "with zero:\t";
    printAssertEquals(5, greaterOf2(5, 0));
    std::cout << "negative:\t";
    printAssertEquals(-2, greaterOf2(-5, -2));
    std::cout << "--done--" <<std::endl;
}

void testGreaterOf3(){
    std::cout << "-------testGreaterOf3---------" <<std::endl;
    //TODO
    std::cout << "Larger first:\t";
    printAssertEquals(9, greaterOf3(9,5,3));
    std::cout << "Larger last:\t";
    printAssertEquals(7, greaterOf3(2,6,7));
    std::cout << "Larger middle:\t";
    printAssertEquals(33, greaterOf3(2,33,7));
    std::cout << "First two equal:\t";
    printAssertEquals(15, greaterOf3(15, 15,13));
    std::cout << "Last two equal:\t";
    printAssertEquals(44, greaterOf3(8, 44,44));
    std::cout << "First and last equal:\t";
    printAssertEquals(13, greaterOf3(13,5,13));
    std::cout << "All equal:\t";
    printAssertEquals(10, greaterOf3(10, 10,10));
    std::cout << "with zero:\t";
    printAssertEquals(5, greaterOf3(3,5, 0));
    std::cout << "negative:\t";
    printAssertEquals(-2, greaterOf3(-5, -2,-10));
    std::cout << "--done--" <<std::endl;

    std::cout << "--done--" <<std::endl;}

void testCanBeTriangle(){
    std::cout << "-------testCanBeTriangle---------" <<std::endl;
    //TODO fill in text about each test case
    std::cout << "normal triangle:\t";
    printAssertEquals(true, canBeTriangle(3, 4, 5));
    std::cout << "Isosceles triangle, side3 is smallest:\t";
    printAssertEquals(true, canBeTriangle(5, 5, 8));
    std::cout << "Isosceles triangle, side3 is biggest:\t";
    printAssertEquals(true, canBeTriangle(10, 10, 8));
    std::cout << "Equilateral triangle:\t";
    printAssertEquals(true, canBeTriangle(5, 5, 5));
    std::cout << "side1 is smallest and side3 side biggest:\t";
    printAssertEquals(true, canBeTriangle(10, 11, 20));
    std::cout << "side1+side2=side3:\t";
    printAssertEquals(false, canBeTriangle(10, 11, 21));
    std::cout << "side3+side2<side1:\t";
    printAssertEquals(false, canBeTriangle(20, 10, 10));
    std::cout << "All sides are negative:\t";
    printAssertEquals(false, canBeTriangle(-2, -3, -5));
    std::cout << "side1 is negative:\t";
    printAssertEquals(false, canBeTriangle(-2, 5, 5));
    std::cout << "side2 is negative::\t";
    printAssertEquals(false, canBeTriangle(2, -5, 5));
    std::cout << "side3 is negative:\t";
    printAssertEquals(false, canBeTriangle(2, 5, -5));
    std::cout << "side2 is the biggest, side1 is smallest:\t";
    printAssertEquals(true, canBeTriangle(3, 5, 4));
    std::cout << "side1 is biggest, side2 is smallest :\t";
    printAssertEquals(true, canBeTriangle(5, 3, 4));
    std::cout << "side1 is biggest, side3 is smallest:\t";
    printAssertEquals(true, canBeTriangle(5, 4, 3));
    std::cout << "side2 is biggest, side3 is smallest :\t";
    printAssertEquals(true, canBeTriangle(4, 5, 3));

    std::cout << "--done--" <<std::endl;
}

void testGenRandInt(int min, int max){
    std::cout << "Should be printing all numbers between " << min << " and " << max << " inclusive:" << std::endl;
    //TODO use a loop to call the function many times (enough to see all possibilities) and print results all on one line


    int number = genRandInt(min,max);

    for(int i=min; i<= max; i++) {
        while (number != i) {
            number = genRandInt(min, max);
        }

        std::cout << number;
    }

    std::cout << std::endl;
}

void testGenRandInt(){
    std::cout << "-------testGenRandInt---------" <<std::endl;
    testGenRandInt(1, 6);
    testGenRandInt(5, 9);
    testGenRandInt(-30, -26);
    testGenRandInt(-3, 3);
    testGenRandInt(6, 1);
    
    std::cout << "Testing generating a single value:\t"<<std::endl;
    printAssertEquals(0, genRandInt(0, 0));
    printAssertEquals(1, genRandInt(1, 1));
    printAssertEquals(10, genRandInt(10, 10));
    printAssertEquals(-1, genRandInt(-1, -1));
    std::cout << "--done--" <<std::endl;
}

void testGenRandTriangle(){
    //TODO
    std::cout << "-----testGenRandTriangle-----" <<std::endl;
    std::cout << "positive min and max:\t"<<std::endl;
    printRandomTriangle(2, 12);
    std::cout << "min and max are equal:\t"<<std::endl;
    printRandomTriangle(30, 30);
    std::cout << "max is smaller than min:\t"<<std::endl;
    printRandomTriangle(23, 2);
    std::cout << "min is negative:\t"<<std::endl;
    printRandomTriangle(-1, 22);
    std::cout << "max is negative:\t"<<std::endl;
    printRandomTriangle(6, -21);
    std::cout << "all are negative:\t"<<std::endl;
    printRandomTriangle(-20, -9);
    std::cout << "min are 0:\t"<<std::endl;
    printRandomTriangle(0, 22);
    std::cout << "max are zero:\t"<<std::endl;
    printRandomTriangle(6, 0);
    std::cout << "all are zero\t"<<std::endl;
    printRandomTriangle(0, 0);
    std::cout << "--done--"<<std::endl;
}

int main(){
    //seeding the random number generator
    srand(time(NULL));

    testGreaterOf2();
    testGreaterOf3();
    testCanBeTriangle();
    testGenRandInt();
    testGenRandTriangle();

    return 0;
}
