//
// Created by Mariama Diallo on 12/8/19.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include <string>

class SongsLinkedNode {

private:

    double duration;
    std::string songTitle;
    std::string artistName;
   SongsLinkedNode* next;

public:
    SongsLinkedNode(std::string songTitle, std::string artistName, double duration);
    SongsLinkedNode(const SongsLinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    std::string getSongTitle();
    std::string getArtistName();
    double getDuration();
    SongsLinkedNode* getNext();
    void setArtistName(std::string newArtistName);
    void setSongName(std::string songName);


    void setDuration(double durationCount);
    void setNext(SongsLinkedNode* newNext);

    void printSongs();
};


#endif //LINKEDNODE_H
