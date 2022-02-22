//
// Created by leianna chen on 2019/9/24.
//
#include <iostream>
#include "ArrayLibRec.h"
/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
 // this is tail function because the base is return a number, and Recursive return by call the function itself again.
int find(const int* const arrayPtr, const int size, const int numToFind, const int num){
    if (size<=0){
        return -1;
    }else{
        if(arrayPtr[num]==numToFind){
            return num;
        }
        else{
            return find(arrayPtr,size-1,numToFind,num+1);
        }
    }
}
int find(const int* const arrayPtr, const int size, const int numToFind){
    return find(arrayPtr,size,numToFind,0);
}
/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
// this is tail function because the base is return a number, and Recursive return by call the function itself again.
int findLast(const int* const arrayPtr, const int size, const int numToFind,const int num) {
    if (size<=0){
        return -1;
    }else{
        if(arrayPtr[num]==numToFind){
            return num;
        }
        else{
            return findLast(arrayPtr,size-1,numToFind,num-1);
        }
    }
}
int findLast(const int* const arrayPtr, const int size, const int numToFind){
    return findLast(arrayPtr,size,numToFind,size-1);
}


/**
 * finds the index of largest value in the array
 * @throws an std::invalid_argument exception if size < 1
 * @return the first index of the maximum value
 */
// this is tail function because the base is return a number, and Recursive return by call the function itself again.
int findMaxIndex(const int* const arrayPtr, const int size,const int currentM,const int index,const int num){
    if(size==1){
        return num;
    } else{
        if(arrayPtr[index+1]>currentM){
            return findMaxIndex(arrayPtr,size-1,arrayPtr[index+1],index+1,index+1);
        }else{
            return findMaxIndex(arrayPtr,size-1,currentM,index+1,num);
        }
    }
}
int findMaxIndex(const int* const arrayPtr, const int size){
    if(size<1) {
        throw std::invalid_argument("Array size must be > 0");
    }else{
        return findMaxIndex(arrayPtr,size,arrayPtr[0],0,0);
    }
}

/**
 * creates a string version of an int array for easy printing
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
// this is tail function because the base is return a number, and Recursive return by call the function itself again.
std::string toString(const int* const arrayPtr, const int size, const int num,const std::string list){
    if(num==size){
        return list;
    }
    else if(num+1==size) {
        return toString(arrayPtr,size,num+1,list + std::to_string(arrayPtr[num])+ "}");
    }
    else{
        return toString(arrayPtr,size,num+1,list + std::to_string(arrayPtr[num]) + ", ");
    }

}
std::string toString(const int* const arrayPtr, const int size){
    if(size<1){
        return "{}";
    }else{
        return toString(arrayPtr,size,0,"{");
    }

}

/**
 * uses binary search on an int array for a certain value
 * @pre the array must be sorted before this function is called
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
// this is tail function because the base is return a number, and Recursive return by call the findLast function.
int binFind(const int* const arrayPtr, const int size, const int numToFind){
    if(size<1){
        return -1;
    }
    else{
        return find(arrayPtr,size,numToFind);
    }
}

