//
// Created by Mariama Diallo on 12/4/19.
//  PlaylistLinkedqueue implementation file
//
#include <string>
#include <fstream>
#include <iostream>
#include "PlaylistLinkedQueue.h"
#include "SongsLinkedNode.h"
using namespace std;


//Creates an empty playlist queue
PlaylistLinkedQueue::PlaylistLinkedQueue(){
    front = nullptr;
    end = nullptr;
    double duration;
}


//adds a song to the end of the queue
void PlaylistLinkedQueue::enqueue(std::string songToAdd, std::string artistToAdd, double slToAdd){
    SongsLinkedNode* newNode = new SongsLinkedNode(songToAdd,  artistToAdd,  slToAdd);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
std::string PlaylistLinkedQueue::dequeue(){
    //TODO, consider cases where:
    // the queue is empty
    // the queue has one item
    // the queue has many items

    if( isEmpty()){
        throw std::out_of_range("queue is empty");
    }
    else {
        if(front == end){
            end = nullptr;
        }
        std::string str=front->getSongTitle();
        SongsLinkedNode *newNode = front;
        front = newNode->getNext();
        delete newNode;
        return str;
    }

}

void PlaylistLinkedQueue::removeSong(std::string songTitle, std::string artistName, double songDuration) {
    std::cout<<" "+artistName+" " +songTitle +" " + to_string(songDuration)+" deleting song from playlist"<<std::endl;
    if( isEmpty()){
        throw std::out_of_range("queue is empty");
    }
    else {
        std::string itemReturn;
        if(front->getSongTitle()==songTitle && front->getArtistName()==artistName && front->getDuration()==songDuration){
            if(front==end){
                front= nullptr;
            }else{
                front=front->getNext();
            }
        }else {
            //copy the entire song list
            SongsLinkedNode* copyNode = this->front;
            PlaylistLinkedQueue newCopy = PlaylistLinkedQueue();

            int num = 0;
            while (front!= nullptr) {
                if(front->getSongTitle()== songTitle && front->getArtistName()== artistName && front->getDuration()==songDuration){
                    num = num + 1;

                }else{
                    newCopy.enqueue(front->getSongTitle(),front->getArtistName(),front->getDuration());
                }
                front = front->getNext();
            }
//            std::string check;
//            newCopy.allSongsInPlaylist(check);
            this->front = newCopy.front;
            this->end = newCopy.end;

        }
    }
}

//returns true if the queue has no items, false otherwise
bool PlaylistLinkedQueue::isEmpty(){
    return front == nullptr;
}
SongsLinkedNode* PlaylistLinkedQueue::playNext(){
     return front->getNext();

}

SongsLinkedNode* PlaylistLinkedQueue::returnBegin(){
    SongsLinkedNode* copyFront = front;
    return copyFront;
}

//prints the next song information, then that song is deleted
void PlaylistLinkedQueue::playNextSong(std::string plName) {
    while (front->getNext() != nullptr){
        SongsLinkedNode *current = this->front;
        current = current->getNext();

        std::cout << plName + "next song: " << std::endl;

        current->printSongs();
        front->getNext();
        dequeue();
    }
}
///Liz: This  class in particular needs PlayListLinkedQueue to have a name to go into a specific
///playlist not just anything
///the parameters are based off of the addCommand
void PlaylistLinkedQueue::addSongEnd(string playListName,string artistName,string songTitle ){

    enqueue(songTitle,artistName,5);
}




/**
    * calculates the duration of a playlist
    * @return the duration
    */
double PlaylistLinkedQueue ::  calcDuration() {
    double totalDuration = 0.0;

    SongsLinkedNode *current = this->front;

    while (current != nullptr) {
        totalDuration += current->getDuration();
        current = current->getNext();
    }
    return totalDuration;
}

/**
    * displays all songs in a playlist
    * @return a string representation of all songs listed
    */

void PlaylistLinkedQueue ::  allSongsInPlaylist(std::string namePL){
    ///Playlist needs a property name for this to apply to a specific playlist-liz
    ///the string is just being used to print
    SongsLinkedNode* current=this->front;
    int x=1;
    std::cout<<namePL+"full playlist"<<std::endl;

    while(current!= nullptr){
        std::cout<<x<<std::endl;
        current->printSongs();
        current=current->getNext();
        x+=1;

    }

}

//Reads the ListofSongs.txt file
void PlaylistLinkedQueue ::ReadFromFile(){
    std::ifstream in;
    in.open("ListofSongs.txt") ;
    std::string songTitle, artistName, duration;

//    std::cout << in.is_open() << std::endl;
    PlaylistLinkedQueue newSonglist = PlaylistLinkedQueue();
    while (!in.eof())
    {
        getline(in, songTitle, '\n');
        getline(in, artistName, '\n');
        getline(in, duration, '\n');
        enqueue(songTitle, artistName, std::stod(duration));

    }


}
//Writes to the ListofSongs.txt file
void PlaylistLinkedQueue :: WriteToFile(std::string songToAdd, std::string artistToAdd, std::string slToAdd){
    //test if it's in library
    std::ifstream in;
    in.open("ListofSongs.txt") ;
    std::string songTitle, artistName, duration;
    while (!in.eof())
    {
        getline(in, songTitle, '\n');
        getline(in, artistName, '\n');
        getline(in, duration, '\n');
        if(songTitle==songToAdd&& artistName==artistToAdd && duration==slToAdd){
             throw std::out_of_range("WriteToFile: song repeats");
        }
    }
    //write a song
    std::ofstream writeFile ("ListofSongs.txt",std::ios_base::app | std::ios_base::out);
    if (writeFile.is_open())
    {
        writeFile <<"\n"<<songToAdd<<"\n";
        writeFile << artistToAdd<<"\n";
        writeFile << slToAdd;
        writeFile.close();
    }
    else{
        throw std::out_of_range("WriteToFile: Files not open");
    }
}




