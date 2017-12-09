//Author: Aaron Nicanor
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include "item.h"

using namespace std;

class room{

    private:
        
        int ID;
        string desc;
        bool north, east, south, west, endgameRoom;
        item puzzlePiece;
        int nRoom, eRoom, sRoom, wRoom;

    public:

        //Commands that the player will use
        bool finalRoom();
        //If the player enters this room, they will win the game

        bool hasExit(char);
        //Checks if the player can go in the directon they inputed into the system

        room changeRoom(char);
        //Changes the player's current room

        bool puzzleSolver(item);
        //Used when the player attemps to solve the room's puzzle
        
        item grabItem(item&);
        //Let's the user grab an item from the room
        
        bool checkItem();
        //sees if there's an item in the room
        
        int getID();
        //checks the room's ID


        //Commands that the developer will use to set up the room's functions
        void setExits(bool, bool, bool, bool);
        //Sets up where the room can be exited from
        
        void setRooms(int, char);
        //Sets up other rooms as exit points

        void setDesc(string);
        //Gives the room a description of what's inside and where its exit points are
        
        void setID(int);
        //Gives the room an ID that it can match with an item to solve said room's puzzle

        void readDesc();
        //Reads out the description of the room

        void removeItem();
        //Removes item from room once it has been taken.
        
        void giveItem(item);
        //Places an item for the user to take

        void includeItem(bool);
        //Lets the program know that there's something in that room
        
        void setEndgame();
        //Makes a room an endgame room
};


#endif


