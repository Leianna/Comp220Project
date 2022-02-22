#include <ctime>
#include <cstdlib>
#include <iostream>

/**
 * generates a random integer. If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return an integer between min and max inclusive (i.e., including both min and max)
 */
int genRandInt(int min, int max, int* numLinesRun){
    (*numLinesRun)+= 4; //parameters+int random
    int random;
    (*numLinesRun)+= 1; //starting for loop
    if (max>min){
        random = rand()% (max-min+1)+min;
        (*numLinesRun)+= 1;
    }
    else{
        random = rand()% (min-max+1)+max;
        (*numLinesRun)+= 1;
    }
    (*numLinesRun)+= 1;
    return random;

}


/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int* genRandArray(int size, int min, int max, int* numLinesRun){
    int* array = new int[size];
    (*numLinesRun)+= 6;//parameters+array+ if statement
    if (size<1){
        (*numLinesRun)+= 1;//return
        return nullptr;
    }
    else{
        (*numLinesRun)+= 1;//if loop
        if (min<max){
            (*numLinesRun)+= 2;//for loop
            for (int i = 0; i<size;i++){
                (*numLinesRun)+= 3;
                array[i]=rand()%(max-min+1)+min;
            }
            (*numLinesRun)+= 1;//return
            return array;
        }
        else{
            (*numLinesRun)+= 2;//for loop
            for (int i = 0; i<size;i++){
                (*numLinesRun)+= 3;
                array[i]=rand()%(min-max+1)+max;
            }
            (*numLinesRun)+= 1;//return
            return array;
        }


    }
}

/**
 * creates a string representation of an int array for easy printing
 * Note: we just use this to view array contents, so we don't need to time it...
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
std::string toString(int* arrayPtr, int size){
    std::string result = "{";
    if(size<1){
        result="{}";
    }
    else{
        for (int i = 0; i<size;i++){
            result = result + std::to_string(arrayPtr[i]) ;
            if (i == size-1){
                result = result + "}";
            } else{
                result = result + ", ";
            }
        }
    }
    return result;
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int find(const int* arrayPtr, int size, int numToFind, int* numLinesRun){
    (*numLinesRun)+= 5;//parameters + if statement
    if(size<1){
        (*numLinesRun)+= 1;//return
        return -1;
    } else{
        (*numLinesRun)+= 2;//while
        int num=0;
        while(num<size && arrayPtr[num]!=numToFind){
            num++;
            (*numLinesRun)+= 2;
        }
        (*numLinesRun)+= 1;//if
        if(arrayPtr[num]!=numToFind){
            (*numLinesRun)+= 1;//return
            return -1;
        } else{
            (*numLinesRun)+= 1;//return
            return num;
        }
    }
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int findLast(const int* arrayPtr, int size, int numToFind, int* numLinesRun){
    (*numLinesRun)+= 6;//parameters + result + if
    int result;
    if (size < 1){
        (*numLinesRun)+= 1;
        result = -1;
    }
    else{
        (*numLinesRun)+= 3;
        result = -1;
        for(int i = 0; i<=size; i++){
            (*numLinesRun)+= 3;
            if(arrayPtr[i]==numToFind){
                (*numLinesRun)+= 1;
                result = i;
            }
        }
    }
    (*numLinesRun)+= 1;//return
    return result;
}

/**
 * finds the index of largest value in the array
 * @throws an std::invalid_argument exception if size < 1
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return the first index of the maximum value
 */
int findMaxIndex(const int* arrayPtr, int size, int* numLinesRun){
    (*numLinesRun)+= 4;
    if(size<1){
        (*numLinesRun)+= 1;
        throw std::invalid_argument("Array size must be > 0");
    } else {
        (*numLinesRun)+= 4;//for loop + max + point
        int max = arrayPtr[0];
        int point = 0;
        for (int i = 0; i < size; i++) {
            (*numLinesRun)+= 3;//for and if
            if (arrayPtr[i] > max) {
                (*numLinesRun)+= 2;
                max = arrayPtr[i];
                point = i;
            }
        }
        (*numLinesRun)+= 1;//return
        return point;
    }
}

/**
 * generates a copy of a given array
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the copy array, which must be deleted by the user, or nullptr, if size < 1
 */
int* copyArray(const int* arrayToCopy, int size, int* numLinesRun){
    (*numLinesRun)+= 4;
    if(size<1){
        (*numLinesRun)+= 1;
        return nullptr;
    }else{
        (*numLinesRun)+= 3;
        int* copyArray = new int[size];
        for(int i = 0 ; i < size ; i++){
            (*numLinesRun)+= 3;
            copyArray[i]=arrayToCopy[i];
        }
        (*numLinesRun)+= 1;
        return copyArray;
    }
}

/**
 * Generates an array with all values 1 through size occurring once each, shuffled in random order
 * example: genShuffledArray(5) might yield {2, 1, 4, 5, 3}
 * @pre srand must be called once before this function is used the first time
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int* genShuffledArray(int size, int* numLinesRun){
    (*numLinesRun)+= 3;
    if (size < 1){
        (*numLinesRun)+= 1;
        return nullptr;
    } else{
        (*numLinesRun)+= 4;
        int* aList = new int[size];
        int* bList = new int[size];
        for(int x = 0; x < size ; x++){
            (*numLinesRun)+= 3;
            bList[x]=x+1;
        }
        (*numLinesRun)+= 2;
        for(int y = 0; y < size ; y++){
            (*numLinesRun)+= 4;
            aList[y] = rand() % size + 1;
            while (find(bList,size,aList[y],numLinesRun)==-1){
                aList[y] = rand() % size + 1;
                (*numLinesRun)+= 2;
            }
            (*numLinesRun)+= 1;
            while (find(bList,size,aList[y],numLinesRun)!=-1){
                (*numLinesRun)+= 2;
                for(int z = 0; z < size ; z++){
                    (*numLinesRun)+= 1;//if
                    if(bList[z]==aList[y]){
                        (*numLinesRun)+= 1;
                        bList[z]=-1;
                    }
                    (*numLinesRun)+= 2;//for
                }
                (*numLinesRun)+= 1;//while
            }
        }

        (*numLinesRun)+= 1;
        return aList;
    }
}

/**
 * Counts the number of times a certain value occurs within an array
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return the count of occurrences of numToFind if it is present, otherwise returns 0
 */
int countOccurrences(const int* arrayPtr, int size, int numToFind, int* numLinesRun){
    (*numLinesRun)+= 5;//parameters + count
    int count = 0;
    (*numLinesRun)+= 2;//for
    for(int i = 0; i<size; i++){
        (*numLinesRun)+= 3;//for + if
        if(arrayPtr[i] == numToFind){
            (*numLinesRun)+= 1;
            count+=1;
        }
    }
    (*numLinesRun)+= 1;//return
    return count;

}

/**
 * @post numLinesRun is updated to include lines run by this function
 * @post the array is sorted in ascending order (from min to max values)
 */
void sort(int* arrayToSort, int size, int* numLinesRun){
    (*numLinesRun)+= 5;//parameters + num +minIndex
    int num;
    int minIndex;
    (*numLinesRun)+= 2;//for
    for(int i = 0; i < size-1 ; i++){
        (*numLinesRun)+= 5;//for
        minIndex = i;
        for(int y = i+1; y < size;y++) {
            (*numLinesRun)+= 3;//for + if
            if (arrayToSort[y]<arrayToSort[minIndex]) {
                (*numLinesRun)+= 1;
                minIndex = y;
            }
        }
        (*numLinesRun)+= 1;//if
        if(minIndex!=i){
            (*numLinesRun)+= 3;
            num = arrayToSort[minIndex];
            arrayToSort[minIndex] = arrayToSort[i];
            arrayToSort[i] = num;
        }
    }
}
