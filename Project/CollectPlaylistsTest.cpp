
#include <iostream>
#include "TestLib.h"
#include "PlaylistLinkedQueue.h"
#include "CollectPlaylists.h"
#include "CollectLinkedList.h"
using namespace std;

void testCollectLinkedList(){
    //4 songList
    PlaylistLinkedQueue playList1 = PlaylistLinkedQueue();
    playList1.enqueue("AAAAA1", "aaaaa1", 5.41);
    playList1.enqueue("AAAAA2", "aaaaa2", 5.11);
    playList1.enqueue("AAAAA3", "aaaaa3", 7.41);

    PlaylistLinkedQueue playList2 = PlaylistLinkedQueue();
    playList2.enqueue("BBBBB1", "bbbbb1", 5.00);
    playList2.enqueue("BBBBB2", "bbbbb2", 4.24);
    playList2.enqueue("BBBBB3", "bbbbb3", 6.41);

    PlaylistLinkedQueue playList3 = PlaylistLinkedQueue();
    playList3.enqueue("CCCCC1", "ccccc1", 4.00);
    playList3.enqueue("CCCCC2", "ccccc2", 3.24);
    playList3.enqueue("CCCCC3", "ccccc3", 6.01);

    PlaylistLinkedQueue playList4 = PlaylistLinkedQueue();

    //Create a collection of song lists---------------------
    CollectLinkedList songCollection;
    std::cout << "Test-itemCount(), insertAtEnd(), removeValueAt()" << std::endl;

    std::cout << "Add first Playlist-expect 1: ";
    songCollection.addPlaylist("songA",playList1);
    printAssertEquals(1,songCollection.itemCount());

    std::cout << "Add second Playlist-expect 2: ";
    songCollection.addPlaylist("songB",playList2);
    printAssertEquals(2,songCollection.itemCount());

    std::cout << "Add third Playlist-expect 3: ";
    songCollection.addPlaylist("songC",playList3);
    printAssertEquals(3,songCollection.itemCount());

    std::cout << "Add fourth Playlist-expect 4: ";
    songCollection.addPlaylist("songD",playList4);
    printAssertEquals(4,songCollection.itemCount());

    std::cout << "remove empty Playlist-expect 3: ";
    songCollection.removeEmpty();
    printAssertEquals(3,songCollection.itemCount());
    std::cout << "---------------------------------------" << std::endl;

    //get the index address---------------------------------------
    int address1 = songCollection.find("songA");
    int address2 = songCollection.find("songB");
    int address3 = songCollection.find("songC");
    std::cout << "Test-getTitleValue(), find(), PrintAllTitle(): " << std::endl;
    std::cout << songCollection.getTitleValueAt(address1) << std::endl;
    std::cout << songCollection.getTitleValueAt(address2) << std::endl;
    std::cout << songCollection.getTitleValueAt(address3) << std::endl;
    std::cout << songCollection.PrintAllTitle() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    //test display the song on one playlist----------------------
//    std::string SongsList;
    std::cout << "Test-displayAll()/getAddressValue() " << std::endl;
    songCollection.displayAll();
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Test-displaySelect()/SongA " << std::endl;
    songCollection.displaySelect("songA");
    std::cout << "---------------------------------------" << std::endl;


}

void testRandomPlaylist(){
    std::cout << "Test-getRandom() " << std::endl;
    CollectLinkedList randomSongCollection;
    randomSongCollection.RandomList("RandomA",9.0);
    std::cout << "less than 9 :"<<randomSongCollection.PrintAllTitle()<<std::endl;
    randomSongCollection.displaySelect("RandomA");
    std::cout << "---------------------------------------" << std::endl;
    CollectLinkedList randomSongCollection2;
    randomSongCollection2.RandomList("RandomB",15.8);
    std::cout <<"less than 15.5 :"<<randomSongCollection2.PrintAllTitle()<<std::endl;
    randomSongCollection2.displaySelect("RandomB");
}
int main(){
    testCollectLinkedList();
    testRandomPlaylist();
    return 0;
}

