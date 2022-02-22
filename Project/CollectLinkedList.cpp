//
// Created by leianna chen on 2019/12/12.
//
#include <string>
#include <fstream>
#include <iostream>
#include "CollectLinkedList.h"
#include "ArrayLib.h"

/**
    * Constructor
*/
CollectLinkedList::CollectLinkedList(){
    this->front = nullptr;
    this->currCount=0;

}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
void CollectLinkedList::addPlaylist(std::string playlistTitleIn, PlaylistLinkedQueue aPointerIn){
    CollectLinkedNode* newNode = new CollectLinkedNode(playlistTitleIn, aPointerIn);
    if(isEmpty()){
        this->front = newNode;
    }
    else{//--------------------------***reinterpret_cast<CollectLinkedNode *>
        CollectLinkedNode* tempNode= this->front;
        while(tempNode->getNext()!= nullptr){
            tempNode=tempNode->getNext();
        }
        tempNode->setNext(newNode);
    }
    this->currCount+=1;
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
std::string CollectLinkedList::getTitleValueAt(int index){

    CollectLinkedNode* node= front;
    if(index<0) {
        throw std::out_of_range("getTitleValueAt");
    }
    if(!isEmpty()) {
        for (int i = 0; i < index; i++) {
            if (node->getNext()== nullptr){
                throw std::out_of_range("getTitleValueAt");
            }
            node = node->getNext();
        }
        return node->getPlaylistTitle();
    }
    else{
        throw std::out_of_range("getTitleValueAt");
    }
}
/**
     * gets a address from the list
     * @param index the location from which to get the address
     * @return a copy of the address at index
     * @throws out_of_range exception if index is invalid
     */
PlaylistLinkedQueue CollectLinkedList::getAddressValueAt(int index){

    CollectLinkedNode* node= front;
    if(index<0) {
        throw std::out_of_range("getAddressValueAt");
    }
    if(!isEmpty()) {
        for (int i = 0; i < index; i++) {
            if (node->getNext()== nullptr){
                throw std::out_of_range("getAddressValueAt");
            }
            node = node->getNext();
        }
        return node->getPlaylistLink();
    }
    else{
        throw std::out_of_range("getAddressValueAt");
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
std::string CollectLinkedList::PrintAllTitle(){
    std::string result = "{";

    CollectLinkedNode* tempNode= front;
    if(itemCount()<1){
        result="{}";
        return result;
    }
    else{
        while(tempNode->getNext()!= nullptr){
            double tempDuration = tempNode->getPlaylistLink().calcDuration();
            result+=tempNode->getPlaylistTitle()+ " - " + std::to_string(tempDuration)+", ";
            tempNode=tempNode->getNext();
        }
        result+=tempNode->getPlaylistTitle()+ " - " + std::to_string(tempNode->getPlaylistLink().calcDuration());
        result+="}";
        return result;
    }

}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
bool CollectLinkedList::isEmpty(){
    if(itemCount()==0){
        return true;
    }else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int CollectLinkedList::itemCount(){
    return currCount;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
void CollectLinkedList::clearList(){
    if(front!=nullptr){

        CollectLinkedNode* tempNode= front;
        CollectLinkedNode* nextNode=front->getNext();

        while(tempNode->getNext()!= nullptr){
            delete tempNode;
            tempNode=nextNode;
            nextNode=tempNode->getNext();
        }
        delete tempNode;
        front= nullptr;
    }
    currCount=0;
}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int CollectLinkedList::find(std::string playlistTitleIn){
    int result = -1;

    CollectLinkedNode* tempNode = front;
    if (front != nullptr){
        result = result+1;
        while(tempNode->getNext() != nullptr){
            if(tempNode->getPlaylistTitle() == playlistTitleIn){
                return result;
            }
            result +=1;
            tempNode = tempNode->getNext();
        }
        if(tempNode->getPlaylistTitle() == playlistTitleIn){
            return result;
        }
        return -1;
    }
    return result;
}


/**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
std::string CollectLinkedList::removeValueAt(int index){
    CollectLinkedNode *tempNode = this->front;
    CollectLinkedNode *tempNodeBefore = this->front;
    if (index < 0 || index > currCount || isEmpty()) {
        throw std::out_of_range("Index Invalid");
    }
    if (index == 0) {
        std::string result = front->getPlaylistTitle();
        front=front->getNext();
        this->currCount-=1;
        return result;
    } else {
        for (int i = 1; i < index; i++) {
            tempNodeBefore = tempNode;
            tempNode = tempNode->getNext();
        }
        std::string itemReturn = tempNode->getPlaylistTitle();
        tempNodeBefore->setNext(tempNode->getNext());
        this->currCount -= 1;
        return itemReturn;
    }
}
/**
     * remove a playlist from the linked list if the playlist is empty
     */
void CollectLinkedList::removeEmpty(){
    CollectLinkedNode *tempNode = this->front;
    int countIndex = 1;
    while (tempNode != nullptr){
        if(tempNode->getPlaylistLink().isEmpty()){
            removeValueAt(countIndex);
        }
        tempNode = tempNode->getNext();
        countIndex = countIndex +1;
    }
}
/**
     * print out all the songs in all playlist
     */
void CollectLinkedList::displayAll(){
    if(currCount!=0) {
        int index = 1;
        CollectLinkedNode *tempNode = this->front;
        while (tempNode != nullptr) {
            std::cout << "Playlist: " << index << std::endl;
            tempNode->getPlaylistLink().allSongsInPlaylist(tempNode->getPlaylistTitle());
            tempNode = tempNode->getNext();
            index = index + 1;
        }
    }

}
/**
 * print out songs from the playlist choose
 * @param playlistTitleIn
 */
void CollectLinkedList::displaySelect(std::string playlistTitleIn){
    std::string SongsList;
    int address = find(playlistTitleIn);
    getAddressValueAt(address).allSongsInPlaylist(SongsList);
}

/**
 * get a random list with songs that are not repeat and in require duration
     * @param playlistTitleIn
     * @param Duration the total duation in a playlist
     */
void CollectLinkedList::RandomList(std::string playlistTitleIn, double Duration){


    PlaylistLinkedQueue testPlaylist = PlaylistLinkedQueue();
    testPlaylist.ReadFromFile();
    //check error if duration enter is longer than all the songs duration in library
    if(testPlaylist.calcDuration()<Duration||Duration<0){
        throw std::out_of_range("RandomList: Duration too long/negative");
    }else{
        //initialize counting number
        double countD = 0.0;//count the total duration
        int counIndex = 0;//count the index in random arraylist
        int numSongs=0;//count how many songs
        int countPath = 1;//#of root

        //calculate how many songs
        std::ifstream openFile ("ListofSongs.txt");
        std::string countTitle = "", countName = "", countDuration = "";
        if (openFile.is_open()){

            while (!openFile.eof())
            {
                getline(openFile, countTitle,'\n');
                getline(openFile, countName,'\n');
                getline(openFile, countDuration,'\n');
                numSongs = numSongs + 1;
            }
            openFile.close();
        }else{
            throw std::out_of_range("RandomList: Files not open");
        }

        //get a random array of number
        int* randomNum = genShuffledArray(numSongs);
//    std::cout<<"Random list: "<<toString(randomNum,numSongs)<<std::endl;


        //creat a playlist
        PlaylistLinkedQueue randomPlaylist = PlaylistLinkedQueue();

        //copy
        while(countD<Duration&&countPath<numSongs){
            PlaylistLinkedQueue copyPlaylist = PlaylistLinkedQueue();
            copyPlaylist.ReadFromFile();
            SongsLinkedNode* frontPtr = copyPlaylist.returnBegin();

            int count = 1;//count num
            while(count!=randomNum[counIndex]){
                frontPtr = frontPtr->getNext();
                count = count+1;
            }
            countD = countD + frontPtr->getDuration();
            if(countD<Duration){
                randomPlaylist.enqueue(frontPtr->getSongTitle(),frontPtr->getArtistName(),frontPtr->getDuration());
            }
            //count
            counIndex = counIndex + 1;
            countPath = countPath + 1;
        }

        //Add to collection of playlists
        addPlaylist(playlistTitleIn,randomPlaylist);
        currCount = currCount+1;
    }


}

