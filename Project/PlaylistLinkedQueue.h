//
//  Created by Mariama Diallo on 12/4/19.
//  PlaylistLinkedqueue interface
//

#ifndef STACKSANDQUEUES_QUEUE_H
#define STACKSANDQUEUES_QUEUE_H

#include <string>
#include <stdexcept>
#include "SongsLinkedNode.h"
#include "PlayList.h"



class PlaylistLinkedQueue: public PlayList {
private:

    PlaylistLinkedQueue(std::string playListName);

    SongsLinkedNode* front;
    SongsLinkedNode* end;
    std::string playListName;
    double duration;



public:

    //Creates an empty playlist queue
    PlaylistLinkedQueue();


    //adds a song to the end of the playlist queue
    void enqueue(std::string songToAdd, std::string artistToAdd, double slToAdd);

    //takes an item off the front of the playlist queue and returns it
    //throws out_of_range exception if the queue is empty

    void removeSong(std::string songTitle, std::string artistName, double songDuration);
    std::string dequeue();
    SongsLinkedNode* returnBegin();

    //returns true if the playlist queue has no songs, false otherwise
    bool isEmpty();

    /**
     * plays the next song info in the playlist list
     * @return the song info
     */


    void playNextSong(std::string plName);
    SongsLinkedNode* playNext();


/**
    * calculates the duration of a playlist
    * @return the duration
    */
    double calcDuration();

/**
    * displays all songs in a playlist
    * @return a string representation of all songs listed
    */

   void allSongsInPlaylist(std::string namePL);


/**
    * Reads songs from file
    * @post prints the songs currently in the song text file
    */
    void ReadFromFile();

    /**
    * Write new user inputs to song file
    * @post the file has an additional value in it, at the end
    */
   void WriteToFile(std::string songToAdd, std::string artistToAdd, std::string slToAdd);


    void allSongsInPlaylist2();

    void addSongEnd();

    void addSongEnd(std::string playListName, std::string artistName, std::string songTitle);
};

#endif //STACKSANDQUEUES_QUEUE_H
