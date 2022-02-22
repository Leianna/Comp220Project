#include <iostream>
#include "ArrayLib.h"
#include <cstdlib>

void compareFindAndFindLast() {
    //TODO
    std::cout << "[Array Size]" << "\t" << "[Find]" << "\t" << "[FindLast]" << std::endl;
    int testFind;
    int testFindLast;
    int timer = 0;
    int max = 30;
    int *testlist = genRandArray(max, 1, max, &timer);


    for (int i = 1; i <= max; i += 1) {
        int timer1 = 0;
        int timer2 = 0;
        testFind = find(testlist, i, 2, &timer1);
        testFindLast = findLast(testlist, i, 2, &timer2);
        std::cout << i << "\t" << timer1 << "\t" << timer2 << std::endl;

    }
    delete[] testlist;
}

void compareFindAndFindMaxIndex(){
    //TODO
    std::cout << "[Array Size]" << "\t" << "[Find]" << "\t" << "[FindMaxIndex]" << std::endl;
    int timer=0;
    int max=30;
    int* testlist = genRandArray(max,1,max,&timer);


    for (int i=1; i<= max; i+=1){
        int timer1 = 0;
        int timer2 = 0;
        int timer3 = 0;
        int num = findMaxIndex(testlist,i,&timer3);
        find(testlist,i,num,&timer1);
        findMaxIndex(testlist,i,&timer2);
        std::cout << i << "\t" << timer1 << "\t" << timer2 << std::endl;

    }
    delete[] testlist;

}

void compareGenRandArrayAndGenShuffledArray(){
    //TODO: the numbers in the for loop might need adjustment to make a nice graph
    std::cout << "[Array Size]" << "\t" << "[RandArray]" << "\t" << "[ShuffArray]" << std::endl;
    int* testArray = new int[0];
    int* testArray2 = new int[0];


    for (int i=1; i<= 61; i+=2){
        int timer1 = 0;
        int timer2 = 0;

        testArray = genRandArray(i, 0, i, &timer1);
        testArray2 = genShuffledArray(i, &timer2);
        std::cout << i << "\t" << timer1 << "\t" << timer2 << std::endl;

        //TODO: ensure there are no memory leaks or dangling pointers.
    }
    delete[](testArray);
    delete[](testArray2);



}

void compareCountOccurrencesAndSort(){
    //TODO
    std::cout << "[Array Size]" << "\t" << "[CountOccurrences]" << "\t" << "[Sort]" << std::endl;
    int timer = 0;
    int max = 30;

    for (int i=1; i<= 50; i+=1){
        int timer1 = 0;
        int timer2 = 0;

        int* testList = genRandArray(max,1,max,&timer);

        countOccurrences(testList,i,2,&timer1);
        sort(testList,i,&timer2);


        std::cout << i << "\t" << timer1 << "\t" << timer2 << std::endl;

        //TODO: ensure there are no memory leaks or dangling pointers.
    }
}

int main() {
    srand(time(NULL));

    compareFindAndFindLast();
    compareFindAndFindMaxIndex();
    compareGenRandArrayAndGenShuffledArray();
    compareCountOccurrencesAndSort();
}
