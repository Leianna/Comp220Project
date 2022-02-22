//
// Created by emurray2 on 12/14/2019.
//
#include "Inventory.h"
#include "CollectLinkedList.h"

#ifndef INC_220GROUPPROJ_INTERFACE_H
#define INC_220GROUPPROJ_INTERFACE_H


class Interface {
private:
    Inventory user;
    CollectLinkedList userCollection;

public:
    Interface();
    void help();
    void main();

};


#endif //INC_220GROUPPROJ_INTERFACE_H
