//
// Created by Toby Dragon on 9/10/18.
//

#ifndef COMP220LAB_ARRAYLIB_H
#define COMP220LAB_ARRAYLIB_H

#include <string>

/**
 * generates a random integer. If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @return an integer between min and max inclusive (i.e., including both min and max)
 */
int genRandInt(int min, int max);


/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int* genRandArray(int size, int min, int max);

/**
 * creates a string representation of an int array for easy printing
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
std::string toString(int* arrayPtr, int size);

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int find(int* arrayPtr, int size, int numToFind);

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int findLast(int* arrayPtr, int size, int numToFind);

/**
 * finds the index of largest value in the array
 * @throws an std::invalid_argument exception if size < 1
 * @return the first index of the maximum value
 */
int findMaxIndex(int* arrayPtr, int size);

/**
 * generates a copy of a given array
 * @return a pointer to the copy array, which must be deleted by the user, or nullptr, if size < 1
 */
int* copyArray(int* arrayToCopy, int size);

/**
 * Generates an array with all values 1 through size occurring once each, shuffled in random order
 * example: genShuffledArray(5) might yield {2, 1, 4, 5, 3}
 * @pre srand must be called once before this function is used the first time
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int* genShuffledArray(int size);

#endif //COMP220LAB_ARRAYLIB_H
