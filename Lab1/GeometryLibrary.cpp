//
// Created by Toby Dragon on 9/4/18.
//
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include "GeometryLibrary.h"

/**
 * @return the largest of the two numbers, or either value if they are equal
    */
    int greaterOf2(int num1, int num2){
        //TODO
        int GreaterOf2Result;
        if(num1<num2){
            GreaterOf2Result = num2;
        }
        else{
            GreaterOf2Result = num1;
        }

        return GreaterOf2Result;
    }

/**
 * @return the largest of the three numbers, or either value if two or more are equally large
 */
    int greaterOf3(int num1, int num2, int num3){
        int greaterOf3Result;
        if (num1 > num2){
            if(num1 < num3){
                greaterOf3Result = num3;
            }
            else{
                greaterOf3Result = num1;
            }
        }
        else if (num1 < num2){
            if(num2 < num3){
                greaterOf3Result = num3;
            }
            else{
                greaterOf3Result = num2;
            }
        }
        else{
            if(num1 < num3){
                greaterOf3Result = num3;
            }
            else{
                greaterOf3Result = num1;
            }
        }
        return greaterOf3Result;
    }

/**
 * generates a random integer. If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @return an integer between min and max inclusive (including both min and max)
 *
 */
    int genRandInt(int min, int max){
        //TODO
        int random;
        if (max>min){
            srand(time(0));
            random = (rand()% max)+min;
        }
        else{
            random = min;
        }

    return random;
}

/**
 * @return true if it is possible to draw a triangle with the 3 integers
 * representing sides, false if not
 */
bool canBeTriangle(int side1, int side2, int side3){
    //TODO
    bool result;
    if(side1<=0 || side2<=0 || side3<=0){
        result = false;
    }
    else if(side1+side2>=side3 && side1+side3>=side2 && side2+side3>=side1){
        result = true;
    }
    else{
        result = false;
    }
    return result;
}

/**
 * generates random values for sides of a triangle with sides between min and max
 * If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @post three valid values for sides of a random triangle are printed to the screen,
 *  in a string like the following:  "side1: 8  side2: 10  side3: 11"
 *  prints "Error, triangle can't be generated from sides given" if it is impossible to make a triangle with the numbers"
 *
 */
void printRandomTriangle(int minSideLength, int maxSideLength) {
    //TODO
    srand(time(0));
    int min = minSideLength;
    int max = maxSideLength;
    if (min > max) {
        min = maxSideLength;
        max = minSideLength;
    }
    if (min <= 0 || max <= 0) {
        std::cout << "Error, triangle can't be generated from sides given" << std::endl;
    }
    else if(min == max){
        std::cout << "side1:" << min << "\tside2:" << min << "\tside3:" << min << std::endl;
    }
    else{
        int side1 = 0;
        int side2 = 0;
        int side3 = 0;
        while (canBeTriangle(side1, side2, side3) == false) {
            side1 = min+(rand()%max);
            side2 = min+(rand()%max);
            side3 = min+(rand()%max);


        }
        std::cout << "side1:" << side1 << "\tside2:" << side2 << "\tside3:" << side3 << std::endl;
    }
}
