//
// Created by emurray2 on 12/14/2019.
//
#include "CollectLinkedList.h"
#include "Interface.h"
Interface::Interface() {};
void Interface::help() {

    string answer;
    cout<<"Commands"<<endl;
    cout<<"Help:Provide a summary of all available commands "<<endl;
    cout<<"Library:Display all songs in the library "<<endl;
    cout<<"artist <artist>: Display all songs for the given artist. "<<endl;
    cout<<"Song<artist,title>:Display information about a particular song "<<endl;
    cout<<"import<filename> Add all songs from the given file to the library.Print a message to the user of any songs that already existed (do not add duplicates) "<<endl;
    cout<<"discontinue <filename>:Display information about a particular song "<<endl;
    cout<<"playlists: display the names of all playlists and their durations "<<endl;
    cout<<"playlist <name>: display all songs left in the given playlist, and the duration (time it will take to play the remaining songs)"<<endl;
    cout<<"new <name>: Make a new empty playlist with the given name"<<endl;
    cout<<"add <name, artist, title> Add the given song to the end of the given playlist"<<endl;
    cout<<"playnext <name>:Print all information about the next song to be played from the given playlist to the screen. Remove that song from the given playlist. Add to the playcount for that song in the library. If the playlist is now empty, it should be removed."<<endl;
    cout<<"If you would like to quit type quit";// should it be exit? what is the main menu?
    cin>>answer;
    if(answer=="Library"){
        user.check();
    }
    else if(answer=="Song<artist,title>"){
        cout<<"What is the name of the artist"<<endl;
        cin>>answer;
        string answer2;
        cout<<"What is the title of their song?";
        user.particularSong(answer,answer2);
    }
    else if(answer=="artists<artists>"){
        cout<<"What is the name of the artist"<<endl;
        cin>>answer;
        user.particularArtist(answer);
    }
    else if(answer=="playlists"){
        //display the names of all of the playlists that exist and their names;
        userCollection.PrintAllTitle();
    }
    else if(answer=="playlist<name>"){
        // the amount of songs in a particular playlists and the amount of time required for all the songs
    }
    else if(answer=="new <name>"){
    }
    else if(answer=="add <name,artist,title>"){
        // addSong to the end of the playlist
        cout<<"What is the artist's name?";
        cin>>answer;
        cout<<"What is the title of the song?";
        string answer2;
        cin>>answer2;
        user.addSong(answer,answer2);
    }
    else if(answer=="playnext <name>"){
        // create and name a new playlist-need maps
    }}

void Interface::main() {
    string answer;
    while(answer!="quit"){
        cout<<"What would you like to do?";
        cin>>answer;
        if (answer=="help"){
            help();
        }



    }

}