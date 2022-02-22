//
// Created by leianna chen on 2019/12/12.
//

#include "CollectLinkedNode.h"
#include <string>

CollectLinkedNode::CollectLinkedNode(std::string playlistTitleIn,PlaylistLinkedQueue aPointer){
    this->playlistTitle = playlistTitleIn;
    this->playlistLink = aPointer;
    next = nullptr;
}

CollectLinkedNode::CollectLinkedNode(const CollectLinkedNode& playlistLinkToCopy){
    playlistLink = playlistLinkToCopy.playlistLink;
    next = nullptr;
}
std::string CollectLinkedNode::getPlaylistTitle(){
    return playlistTitle;
}
PlaylistLinkedQueue CollectLinkedNode::getPlaylistLink(){
    return playlistLink;
}

CollectLinkedNode* CollectLinkedNode::getNext(){
    return next;
}

void CollectLinkedNode::setPlaylistTitle(std::string newPlaylistTitle){
    playlistTitle = newPlaylistTitle;
}

void CollectLinkedNode::setPlaylistLink(PlaylistLinkedQueue newPointer){
    playlistLink = newPointer;
}

void CollectLinkedNode::setNext(CollectLinkedNode* newNext){
    next = newNext;
}
