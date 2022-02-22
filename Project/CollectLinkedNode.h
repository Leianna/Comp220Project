//
// Created by leianna chen on 2019/12/12.
//

#ifndef PROJECT_COLLECTLINKEDNODE_H
#define PROJECT_COLLECTLINKEDNODE_H
#include "PlaylistLinkedQueue.h"



class CollectLinkedNode {
private:
    CollectLinkedNode(PlaylistLinkedQueue aPointer);

    std::string playlistTitle;
    PlaylistLinkedQueue playlistLink;
    CollectLinkedNode* next;

public:
    CollectLinkedNode(std::string playlistTitleIn,PlaylistLinkedQueue aPointer);
    CollectLinkedNode(const CollectLinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    std::string getPlaylistTitle();
    PlaylistLinkedQueue getPlaylistLink();
    CollectLinkedNode* getNext();
    void setPlaylistTitle(std::string newPlaylistTitle);
    void setPlaylistLink(PlaylistLinkedQueue newPointer);
    void setNext(CollectLinkedNode* newNext);
};


#endif //PROJECT_COLLECTLINKEDNODE_H
