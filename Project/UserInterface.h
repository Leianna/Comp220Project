//
// Created by emurray2 on 12/8/2019.
//
#include "PlaylistLinkedQueue.h"
#include "Inventory.h"
#include "CollectLinkedList.h"


#ifndef GITYPART_USERINTERFACE_H
#define GITYPART_USERINTERFACE_H


class UserInterface {
private:

    PlaylistLinkedQueue userPlaylist;
    Inventory userInventory;
    CollectLinkedList userCollection;
    std::string lastName;

public:
    UserInterface();
    void Interface();
    void commandsDJ();
    void help();
    void add(); // add song
    void clear(); // clear inventory
    void deleteStuff(); // delete songs
    void incrementPlay();
    // print everything in a collection,playlist and
    //inventory
    void displayAll();
    // print a particular song,playlist and collection
    void displaySelect();
    // delete everything in inventory,playlist and collection
    void clearAll();
    void deleteFromFile();
    void addToFile();
    void informationSelect();
    void informationAll();
    void saveFile();
    void main();


};


#endif //GITYPART_USERINTERFACE_H
