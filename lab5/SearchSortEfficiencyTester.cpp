//
// Created by leianna chen on 2019/10/12.
//
#include <iostream>
#include "TestLib.h"
#include "ArrayLib.h"
#include <cstdlib>
void Q1(){
    std::cout << "-------Q1Test---------" <<std::endl;
    int timer=0;
    int timer1=0;
    int max=100;
    int* testlist = genRandArray(1000,0,max,timer);
    int* testlist1 = copyArray(testlist,1000,timer);
    sort(testlist1,max,timer1);
    std::cout << "sort: " << timer <<  std::endl;
    std::cout << "[Array Size]" "\t" <<"[Find]"<< "\t" << "[BinFind]" << "\t" << "[Sort]" <<std::endl;
    for (int i=1; i<= max; i+=1){
        int timer2 = 0;
        int timer3 = 0;
        int timer4 = 0;
        find(testlist,i,i,timer2);
        binFind(testlist1,i,i,timer3);
        sort(testlist,i,timer4);
        std::cout << i << "\t" << timer2 << "\t" <<timer3 <<"\t" <<timer4 <<  std::endl;
    }
    delete[] testlist;
}
void Q2(){
    std::cout << "-------Q2Test---------" <<std::endl;
    int timer=0;
    int timer1=0;
    int max=1000;
    int* testlist = genRandArray(1000,0,max,timer);
    int* testlist1 = copyArray(testlist,1000,timer);
    sort(testlist1,max,timer1);
    std::cout << "sort: " << timer <<  std::endl;
    std::cout << "[Array Size]" <<"[unsort-Find]"<< "\t" << "[sort-binFind]" << "\t" <<std::endl;
    for (int i=1; i<= max; i+=1){
        int timer2 = 0;
        int timer3 = 0;
        find(testlist,i,i,timer2);
        binFind(testlist1,i,i,timer3);
        std::cout << i << "\t" << timer2 << "\t" <<timer3<<  std::endl;
    }
    delete[] testlist;
}
void Q3(){
    std::cout << "-------Q3Test---------" <<std::endl;
    int timer=0;
    int max=100;
    int* testlist = genRandArray(1000,0,max,timer);
    std::cout << "[Array Size]" <<"[Sort]"<< "\t" << "[MergeSort]" << "\t" <<std::endl;
    for (int i=1; i<= max; i+=1){
        int timer2 = 0;
        int timer3 = 0;
       sort(testlist,i,timer2);
       mergeSort(testlist,i,timer3);
        std::cout << i << "\t" << timer2 << "\t" <<timer3 <<  std::endl;
    }
    delete[] testlist;
}


int main(){
    Q2();

}