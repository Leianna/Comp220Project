//
// Created by leianna chen on 2019/11/18.
//

#ifndef PROJECT_COLLPLAYLISTS_H
#define PROJECT_COLLPLAYLISTS_H
#include <string>
#include <stdexcept>
#include "PlayList.h"
#include "PlaylistLinkedQueue.h"


class CollectPlaylists {
private:
    //list of playlist name in txt file
    //Private to disable copying and assigning from outside class, don't implement these methods



public:

//    CollectLinkedList listPlaylists = CollectLinkedList();
    CollectPlaylists(){}

    /**
     * add a playlist
     */
    virtual void addPlaylist(std::string playlistTitleIn, PlaylistLinkedQueue aPointer) = 0;

    /**
     * check if the collection of playlist is empty
     * @return
     */
    virtual bool isEmpty() = 0;

    /**
     * display all the songs - title, author, and duration
     */
    virtual void displayAll() = 0;

    /**
     * display selected playlist - song title, author, and duration
     */
    virtual void displaySelect(std::string playlistTitleIn) = 0;

    /**
     * clear entire collection of playlists
     */
    virtual void clearList() = 0;

    /**
     * remove a playlist if it's empty
     */
    virtual void removeEmpty() = 0;


    /**
     * create a random list with random songs from other playlist
     * @param listName
     */
    virtual void RandomList(std::string playlistTitleIn, double Duration) = 0;

};


#endif //PROJECT_COLLPLAYLISTS_H
