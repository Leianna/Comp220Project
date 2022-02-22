//
// Created by Lei Chen on 10/1/19.
//
#include <iostream>
/**
**
* generates a random integer. If the user enters incorrect values (min is greater than max),
* the function recognizes the problem and swaps values to ensure max is greater than min
* @pre the function srand() must be called once before this function is used the first time
* @post numLinesRun is updated to add the number of lines run by this function
* @return an integer between min and max inclusive (i.e., including both min and max)
*/
int genRandInt(int min, int max, int& numLinesRun){
    int random;
    (numLinesRun)+= 1; //starting for loop
    if (max>min){
        random = rand()% (max-min+1)+min;
        (numLinesRun)+= 1;
    }
    else{
        random = rand()% (min-max+1)+max;
        (numLinesRun)+= 1;
    }
    (numLinesRun)+= 1;
    return random;
}


/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int* genRandArray(int size, int min, int max, int& numLinesRun){
    int* array = new int[size];
    (numLinesRun)+= 6;//parameters+array+ if statement
    if (size<1){
        (numLinesRun)+= 1;//return
        return nullptr;
    }
    else{
        (numLinesRun)+= 1;//if loop
        if (min<max){
            (numLinesRun)+= 2;//for loop
            for (int i = 0; i<size;i++){
                (numLinesRun)+= 3;
                array[i]=rand()%(max-min+1)+min;
            }
            (numLinesRun)+= 1;//return
            return array;
        }
        else{
            (numLinesRun)+= 2;//for loop
            for (int i = 0; i<size;i++){
                (numLinesRun)+= 3;
                array[i]=rand()%(min-max+1)+max;
            }
            (numLinesRun)+= 1;//return
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
std::string toString(const int* arrayPtr, int size){
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
int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    (numLinesRun)+= 5;//parameters + if statement
    if(size<1){
        (numLinesRun)+= 1;//return
        return -1;
    } else{
        (numLinesRun)+= 2;//while
        int num=0;
        while(num<size-1 && arrayPtr[num]!=numToFind){
            num++;
            (numLinesRun)+= 2;
        }
        (numLinesRun)+= 1;//if
        if(arrayPtr[num]==numToFind){
            (numLinesRun)+= 1;//return
            return num;
        } else{
            (numLinesRun)+= 1;//return
            return -1;
        }

    }
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    (numLinesRun)+= 6;//parameters + result + if
    int result;
    if (size < 1){
        (numLinesRun)+= 1;
        result = -1;
    }
    else{
        (numLinesRun)+= 3;
        result = -1;
        for(int i = 0; i<=size; i++){
            (numLinesRun)+= 3;
            if(arrayPtr[i]==numToFind){
                (numLinesRun)+= 1;
                result = i;
            }
        }
    }
    (numLinesRun)+= 1;//return
    return result;
}

/**
 * finds the index of largest value in the array
 * @throws an std::invalid_argument exception if size < 1
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return the first index of the maximum value
 */
int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun){
    (numLinesRun)+= 4;
    if(size<1){
        (numLinesRun)+= 1;
        throw std::invalid_argument("Array size must be > 0");
    } else {
        (numLinesRun)+= 4;//for loop + max + point
        int max = arrayPtr[0];
        int point = 0;
        for (int i = 0; i < size; i++) {
            (numLinesRun)+= 3;//for and if
            if (arrayPtr[i] > max) {
                (numLinesRun)+= 2;
                max = arrayPtr[i];
                point = i;
            }
        }
        (numLinesRun)+= 1;//return
        return point;
    }
}

/**
 * generates a copy of a given array
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the copy array, which must be deleted by the user, or nullptr, if size < 1
 */
int* copyArray(const int* arrayToCopy, int size, int& numLinesRun){
    (numLinesRun)+= 4;
    if(size<1){
        (numLinesRun)+= 1;
        return nullptr;
    }else{
        (numLinesRun)+= 3;
        int* copyArray = new int[size];
        for(int i = 0 ; i < size ; i++){
            (numLinesRun)+= 3;
            copyArray[i]=arrayToCopy[i];
        }
        (numLinesRun)+= 1;
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
int* genShuffledArray(int size, int& numLinesRun){
    (numLinesRun)+= 3;
    if (size < 1){
        (numLinesRun)+= 1;
        return nullptr;
    } else {
        (numLinesRun) += 4;
        int *aList = new int[size];
        int *bList = new int[size];
        for (int x = 0; x < size; x++) {
            (numLinesRun) += 3;
            bList[x] = x + 1;
        }
        (numLinesRun) += 2;
        for (int y = 0; y < size; y++) {
            (numLinesRun) += 4;
            aList[y] = rand() % size + 1;
            while (find(bList, size, aList[y], numLinesRun) == -1) {
                aList[y] = rand() % size + 1;
                (numLinesRun) += 2;
            }
            (numLinesRun) += 1;
            while (find(bList, size, aList[y], numLinesRun) != -1) {
                (numLinesRun) += 2;
                for (int z = 0; z < size; z++) {
                    (numLinesRun) += 1;//if
                    if (bList[z] == aList[y]) {
                        (numLinesRun) += 1;
                        bList[z] = -1;
                    }
                    (numLinesRun) += 2;//for
                }
                (numLinesRun) += 1;//while
            }
        }

        (numLinesRun) += 1;
        return aList;
    }
}

/**
 * Counts the number of times a certain value occurs within an array
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return the count of occurrences of numToFind if it is present, otherwise returns 0
 */
int countOccurrences(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    (numLinesRun)+= 5;//parameters + count
    int count = 0;
    (numLinesRun)+= 2;//for
    for(int i = 0; i<size; i++){
        (numLinesRun)+= 3;//for + if
        if(arrayPtr[i] == numToFind){
            (numLinesRun)+= 1;
            count+=1;
        }
    }
    (numLinesRun)+= 1;//return
    return count;
}

/**
 * Selection Sort
 * @post numLinesRun is updated to include lines run by this function
 * @post the array is sorted in ascending order (from min to max values)
 */
void sort(int* arrayToSort, int size, int& numLinesRun){
    (numLinesRun)+= 5;//parameters + num +minIndex
    int num;
    int minIndex;
    (numLinesRun)+= 2;//for
    for(int i = 0; i < size-1 ; i++){
        (numLinesRun)+= 5;//for
        minIndex = i;
        for(int y = i+1; y < size;y++) {
            (numLinesRun)+= 3;//for + if
            if (arrayToSort[y]<arrayToSort[minIndex]) {
                (numLinesRun)+= 1;
                minIndex = y;
            }
        }
        (numLinesRun)+= 1;//if
        if(minIndex!=i){
            (numLinesRun)+= 3;
            num = arrayToSort[minIndex];
            arrayToSort[minIndex] = arrayToSort[i];
            arrayToSort[i] = num;
        }
    }
}

/**
 * uses binary search on an int array for a certain value
 * @pre the array must be sorted before this function is called
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
//int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun,int index,int middle, int end) {
//    if (arrayPtr[middle] == numToFind){
//       return middle;
//    }else if(arrayPtr[middle] < numToFind){
//        if (arrayPtr[end-1]==numToFind){
//            return end-1;
//        }else if ((end-middle-2)>1){
//            return binFind(arrayPtr,size,numToFind,numLinesRun,middle+1,(end-middle-2)/2,end);
//        }else{
//            return -1;
//        }
//   }else{
//        if (arrayPtr[index]==numToFind){
//            return index;
//        }else if ((middle/2)>1){
//            return binFind(arrayPtr,size,numToFind,numLinesRun,index,middle/2,middle);
//        }else{
//            return -1;
//        }
//    }

//}
int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    (numLinesRun)+= 5;
//    if(size<1){
//        (numLinesRun)+= 1;
//        return -1;
//    }
//    else{
//        (numLinesRun)+= 1;
//        int middle = (size-1)/2;
//        return binFind(arrayPtr,size,numToFind,numLinesRun,0,middle,size);
//    }
    if (size==0){
        (numLinesRun)+= 1;
        return -1;
    }
    else if (size==1){
        (numLinesRun)+= 1;
        if (*arrayPtr==numToFind){
            (numLinesRun)+= 1;
            return 0;
        }else{
            (numLinesRun)+= 1;
            return -1;
        }
    }else if (size==2){
        (numLinesRun)+= 1;
        if (*arrayPtr==numToFind){
            (numLinesRun)+= 1;
            return 0;
        }else{
            (numLinesRun)+= 1;
            int idx = binFind(arrayPtr+1, 1, numToFind,numLinesRun);
            (numLinesRun)+= 1;
            if(idx == 0) {
                (numLinesRun)+= 1;
                return 1;
            }else {
                (numLinesRun)+= 1;
                return -1;
            }
        }
    }else{
        (numLinesRun)+= 1;
        if (size%2==0){
            (numLinesRun)+= 2;
            int mid=(size/2)-1;
            if (arrayPtr[mid]==numToFind){
                (numLinesRun)+= 1;
                return mid;
            }
            else if (arrayPtr[mid]<numToFind) {
                (numLinesRun)+= 1;
                int idx = binFind(arrayPtr + mid + 1, size / 2, numToFind,numLinesRun);
                (numLinesRun)+= 1;
                if (idx != -1) {
                    (numLinesRun)+= 1;
                    return mid + 1 + idx;
                }else {
                    (numLinesRun)+= 1;
                    return -1;
                }
            }
            else{
                (numLinesRun)+= 1;
                return binFind(arrayPtr, size/2-1, numToFind,numLinesRun);
            }

        }else{
            (numLinesRun)+= 2;
            int mid=size/2;
            if (arrayPtr[mid]==numToFind){
                (numLinesRun)+= 1;
                return mid;
            }
            else if (arrayPtr[mid]<numToFind){
                (numLinesRun)+= 2;
                int idx=binFind(arrayPtr+mid+1, size/2, numToFind,numLinesRun);
                if (idx!=-1){
                    (numLinesRun)+= 1;
                    return mid+1+idx;
                }
                else{
                    (numLinesRun)+= 1;
                    return idx;
                }
            }else{
                (numLinesRun)+= 1;
                return binFind(arrayPtr, size/2, numToFind,numLinesRun);
            }
        }
    }
}

/**
 * returns an array that is a sorted, merged copy of arrays a1 and a2
 * Operates in O(n), linear time
 * @pre both a1 and a2 must be sorted
 * @post numLinesRun is updated to include lines run by this function
 * @return an array of size (size1+size2) that is an in-order (sorted) copy of all values from a1 and a2,
 *   to be deleted by the user, * or nullptr if (size1+size2) < 1
 */
int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun){
    (numLinesRun)+= 6;
    if ((size1+size2)<1){
        (numLinesRun)+= 1;
        return nullptr;
    }
    (numLinesRun)+= 5;
    int* newArray = new int[size1+size2];
    int num1=0;
    int num2=0;
    int index=0;
    while(index < size1+size2){
        (numLinesRun)+= 1;
        if(num1<size1 && num2<size2) {
            (numLinesRun)+= 1;
            if (a1[num1] < a2[num2]) {
                (numLinesRun)+= 3;
                newArray[index] = a1[num1];
                index++;
                (numLinesRun)+= 1;
                num1++;
            } else {
                (numLinesRun)+= 3;
                newArray[index] = a2[num2];
                index++;
                (numLinesRun)+= 1;
                num2++;
            }
        }else if(num1<size1){
            (numLinesRun)+= 3;
            newArray[index] = a1[num1];
            index++;
            (numLinesRun)+= 1;
            num1++;
        }else if(num2<size2){
            (numLinesRun)+= 3;
            newArray[index] = a2[num2];
            index++;
            (numLinesRun)+= 1;
            num2++;
        }
    }
    (numLinesRun)+= 1;
    return newArray;
//    (numLinesRun)+= 1;
//    if(size1==0 && size2>0){
//        (numLinesRun)+= 1;
//        return copyArray(a2,size2,numLinesRun);
//    } else if(size2==0 && size1 > 0){
//        (numLinesRun)+= 1;
//        return copyArray(a1,size1,numLinesRun);
//    }
//
//    else{
//        (numLinesRun)+= 3;
//        int *result = new int[size1 + size2];
//        for (int i = 0; i < size1; i++){
//            result[i] = a1[i];
//            (numLinesRun)+= 2;
//        }
//        (numLinesRun)+= 2;
//        for (int i = 0; i < size2; i++){
//            (numLinesRun)+= 2;
//            result[i+size1] = a2[i];
//        }
//        (numLinesRun)+= 3;
//        sort(result,size1+size2,numLinesRun);
//        return result;
//        delete[] result;
//    }
}

/**
 * returns a sorted copy of the array using merge sort
 * @post numLinesRun is updated to include lines run by this function
 * @return a copy of the array sorted from min to max values, or nullptr if size < 1, to be deleted by the user
 */
int* mergeSort(const int* arrayToSort, int size, int& numLinesRun){
    (numLinesRun)+= 5;
    int* result0;
    if (size<1){
        (numLinesRun)+= 1;
        return nullptr;
    }
    (numLinesRun)+= 2;
    int* newResult = new int[0];
    if(size==1){
        (numLinesRun)+= 2;
        newResult[0]=arrayToSort[0];
        return newResult;
    }else{
        (numLinesRun)+= 5;
        int* result1;
        int* result2;
        int result1Size;
        int result2Size;;
        if(size%2==0){
            (numLinesRun)+= 2;
            result1Size = size/2;
            result2Size = size/2;
        }else{
            (numLinesRun)+= 2;
            result1Size = size/2;
            result2Size = size/2 + 1;
        }
        (numLinesRun)+= 1;
        result1 = mergeSort(arrayToSort,result1Size,numLinesRun);
        (numLinesRun)+= 1;
        result2 = mergeSort(arrayToSort+result1Size,result2Size,numLinesRun);
        (numLinesRun)+= 1;
        result0 = merge(result1,result1Size,result2,result2Size,numLinesRun);
        (numLinesRun)+= 1;
        return result0;

    }
//        (numLinesRun)+= 3;
//        int *result = new int[size];
//        for (int i = 0; i < size; i++){
//            result[i]=arrayToSort[i];
//            (numLinesRun)+= 2;
//        }
//        (numLinesRun)+= 3;
//        sort(result,size,numLinesRun);
//        return result;
//        delete[] result;

}
