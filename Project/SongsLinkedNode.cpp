//
// Created by Mariama Diallo on 12/8/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include "SongsLinkedNode.h"

SongsLinkedNode::SongsLinkedNode(std::string songTitle, std::string artistName, double duration) {
    this->songTitle=songTitle;
    this->artistName=artistName;
    this->duration=duration;
    next = nullptr;
}

SongsLinkedNode::SongsLinkedNode(const SongsLinkedNode& nodeToCopy){
    songTitle= nodeToCopy.songTitle;
    artistName =nodeToCopy.artistName;
    duration= nodeToCopy.duration;
    next = nullptr;
}

std::string  SongsLinkedNode::getSongTitle(){
    return songTitle;

}

/**
 * gets artist name
 */
std::string  SongsLinkedNode:: getArtistName(){
    return artistName;

}

/**
* gets the song length
*/

double SongsLinkedNode::getDuration(){
    return duration;

}


SongsLinkedNode* SongsLinkedNode::getNext(){
    return next;
}


void SongsLinkedNode::setArtistName(std::string  newArtistName){
    this->artistName=newArtistName;
}
void SongsLinkedNode::setSongName(std::string  songName){
    this->songTitle=songName;
}


void SongsLinkedNode:: setDuration(double durationCount ){
    this->duration=durationCount;
}
void SongsLinkedNode::setNext(SongsLinkedNode* newNext){
    next = newNext;
}
void SongsLinkedNode::printSongs() {

    std::cout<< " Song Name:   " << this->songTitle << std::endl
         << " Artist Name: " << this->artistName <<std:: endl
         << " Song Length: " << this->duration << std:: endl;


}
