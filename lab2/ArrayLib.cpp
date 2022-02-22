//
// Created by Lei chen on 2019/9/16.
//
#include <ctime>
#include <cstdlib>
#include <iostream>
int genRandInt(int min, int max){
    int random;
    srand(time(0));
    if (max>min){
        random = rand()% (max-min)+min;
    }
    else{
        random = rand()% (min-max)+max;
    }

    return random;
}
int* genRandArray(int size, int min, int max){
    int* array = new int[size];

    srand(time(0));
    if (size<1){
        return nullptr;
    }
    else{
        if (min<max){
            for (int i = 0; i<size;i++){
                array[i]=rand()%(max-min)+min;
            }
            return array;
        }
        else{
            for (int i = 0; i<size;i++){
                array[i]=rand()%(min-max)+max;
            }
            return array;
        }


    }
}
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
int find(int* arrayPtr, int size, int numToFind){
    if(size<1){
        return -1;
    } else{
        int num=0;
        while(num<size && arrayPtr[num]!=numToFind){
            num++;
        }
        if(arrayPtr[num]!=numToFind){
            return -1;
        } else{
            return num;
        }
    }
}
int findLast(int* arrayPtr, int size, int numToFind){
    int result;
    if (size < 1){
        result = -1;
    }
    else{
        result = -1;
        for(int i = 0; i<=size; i++){
            if(arrayPtr[i]==numToFind){
                result = i;
            }
        }
    }
    return result;
}
int findMaxIndex(int* arrayPtr, int size){
    if(size<1){
        throw std::invalid_argument("Array size must be > 0");
    } else {
        int max = arrayPtr[0];
        for (int i = 0; i < size; i++) {
            if (arrayPtr[i] > max) {
                max = arrayPtr[i];
            }
        }
        return max;
    }
}
int* copyArray(int* arrayToCopy, int size){

    if(size<1){
        return nullptr;
    }else{
        int* copyArray = new int[size];
        for(int i = 0 ; i < size ; i++){
            copyArray[i]=arrayToCopy[i];
        }
        return copyArray;
    }
}
int* genShuffledArray(int size){
    if (size < 1){
        return nullptr;
    } else{
        int* aList = new int[size];
        int* bList = new int[size];
        for(int x = 0; x < size ; x++){
                bList[x]=x+1;
        }
        srand(time(0));

        for(int y = 0; y < size ; y++){
            aList[y] = rand() % size + 1;
            while (find(bList,size,aList[y])==-1){
                aList[y] = rand() % size + 1;
            }
            while (find(bList,size,aList[y])!=-1){
                for(int z = 0; z < size ; z++){
                    if(bList[z]==aList[y]){
                        bList[z]=-1;
                    }
                }
            }
        }



        return aList;
    }


}