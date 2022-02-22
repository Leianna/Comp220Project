//
// Created by Toby Dragon on 9/4/18.
//

#ifndef LAB1SOLN_GEOMETRYLIBRARY_H
#define LAB1SOLN_GEOMETRYLIBRARY_H

/**
 * @return the largest of the two numbers, or either value if they are equal
 */
int greaterOf2(int num1, int num2);

/**
 * @return the largest of the three numbers, or either value if two or more are equally large
 */
int greaterOf3(int num1, int num2, int num3);

/**
 * generates a random integer. If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @return an integer between min and max inclusive (including both min and max)
 */
int genRandInt(int min, int max);

/**
 * @return true if it is possible to draw a triangle with the 3 integers
 * representing sides, false if not
 */
bool canBeTriangle(int side1, int side2, int side3);

/**
 * generates random values for sides of a triangle with sides between min and max
 * If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @post three valid values for sides of a random triangle are printed to the screen,
 *  in a string like the following:  "side1: 8  side2: 10  side3: 11"
 *  prints "Error, triangle can't be generated" if it is impossible to make a triangle with the numbers"
 *
 */
void printRandomTriangle(int minSideLength, int maxSideLength);

#endif //LAB1SOLN_GEOMETRYLIBRARY_H
