//
// Created by leianna chen on 2019/12/12.
//

#ifndef PROJECT_COLLECTLINKEDLIST_H
#define PROJECT_COLLECTLINKEDLIST_H
#include <string>
#include <stdexcept>
#include "CollectLinkedNode.h"
#include "SongsLinkedNode.h"
#include "PlaylistLinkedQueue.h"
#include "CollectPlaylists.h"
#include "ArrayLib.h"

class CollectLinkedList: public CollectPlaylists {
private:
    CollectLinkedNode* front;
    int currCount;
public:
    /**
     * Constructor
     */
    CollectLinkedList();


    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void addPlaylist(std::string playlistTitleIn, PlaylistLinkedQueue aPointer);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    std::string getTitleValueAt(int index);
    /**
     * gets a address from the list
     * @param index the location from which to get the address
     * @return a copy of the address at index
     * @throws out_of_range exception if index is invalid
     */
    PlaylistLinkedQueue getAddressValueAt(int index);

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    std::string PrintAllTitle();

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int itemCount();

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList();

    /**
     * Searches playlist title for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    int find(std::string playlistTitleIn);


    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    std::string removeValueAt(int index);

    /**
     * remove a playlist from the linked list if the playlist is empty
     */
    void removeEmpty();

    /**
     * print out all the songs in all playlist
     */
    void displayAll();

    /**
     * print out songs from the playlist choose
     * @param playlistTitleIn
     */
    void displaySelect(std::string playlistTitleIn);

    /**
     * get a random list with songs that are not repeat and in require duration
     * @param playlistTitleIn
     * @param Duration the total duration in a playlist
     */
    void RandomList(std::string playlistTitleIn, double Duration);

    //Private to disable copying and assigning from outside class, don't implement these methods
    CollectLinkedList(const CollectLinkedList& arrayListToCopy);
};


#endif //PROJECT_COLLECTLINKEDLIST_H
