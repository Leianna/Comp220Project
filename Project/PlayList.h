//
// Created by Mariama Diallo on 11/19/19.
//

#ifndef PERSONALGROUPPROJ_PLAYLIST_H
#define PERSONALGROUPPROJ_PLAYLIST_H


#include <stdexcept>
#include <string>
#include "SongsLinkedNode.h"


class PlayList{
private:
//Private to disable copying and assigning from outside class, don't implement these methods



public:
    PlayList(){}



    /**
  * appends the new item to the end of the list
  * @post the list has an additional value in it, at the end
  */
    virtual  void enqueue(std::string songToAdd, std::string artistToAdd, double slToAdd)=0;

/**
  * throws out_of_range exception if the playlist is empty
  * removes song item
  */
    virtual void removeSong(std::string songTitle, std::string artistName, double songDuration)=0;    virtual  std::string dequeue()=0;


/**
    * checks if there are any valid items in the playlist
    * @return true if there are no valid items in the playlist, false otherwise
    */
    virtual bool isEmpty()=0;

/**
    * plays the next song in a given playlist
    * Removes the song from the playlist
    * @return a string of the next song
    */

    virtual void playNextSong(std::string plName)=0;
    virtual SongsLinkedNode* playNext()=0;


/**
    * calculates the duration of a playlist
    * @return the duration
    */
    virtual double calcDuration()=0;

/**
    * displays all songs in a playlist
    * @return a string representation of all songs listed
    */
    virtual void allSongsInPlaylist(std::string namePL)=0;
/**
    * Write new user inputs to song file
    * @post the file has an additional value in it, at the end
    */
    virtual void WriteToFile(std::string songToAdd, std::string artistToAdd, std::string slToAdd) = 0;

    /**
    * Reads songs from file
    * @post prints the songs currently in the song text file
    */
    virtual void ReadFromFile()=0;

};

#endif //PERSONALGROUPPROJ_LINKEDPLAYLIST_H
