#ifndef COMP220LAB_RECARRAYLIB_H
#define COMP220LAB_RECARRAYLIB_H

#include <string>

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int find(const int* const arrayPtr, const int size, const int numToFind,const int num);
int find(const int* const arrayPtr, const int size, const int numToFind);
/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int findLast(const int* const arrayPtr, const int size, const int numToFind);
int findLast(const int* const arrayPtr, const int size, const int numToFind,const int num);

/**
 * finds the index of largest value in the array
 * @throws an std::invalid_argument exception if size < 1
 * @return the first index of the maximum value
 */
int findMaxIndex(const int* const arrayPtr, const int size);
int findMaxIndex(const int* const arrayPtr, const int size,const int currentM,const int index,const int num);

/**
 * creates a string version of an int array for easy printing
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
std::string toString(const int* const arrayPtr, const int size);
std::string toString(const int* const arrayPtr, const int size, const int num,const std::string list);

/**
 * uses binary search on an int array for a certain value
 * @pre the array must be sorted before this function is called
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int binFind(const int* const arrayPtr, const int size, const int numToFind);

#endif //COMP220LAB_RECARRAYLIB_H
