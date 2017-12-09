//Author: Aaron Nicanor
#ifndef OBJECTS_H
#define ONJECTS_H

#include <string>
#include <iostream>

using namespace std;

class item{

    private:

        string caller;
        int solveChecker;
        bool real;

    public:

        string name();
        //returns the name of the item

        int puzzleGuess();
        //returns the solveChecker number ID  and sees if it's compatible with the puzzle room's solution number ID

        void giveName(string);
        //gives the item a name

        void giveID(int);
        //gives the item a solveChecker ID, which can then be used to solve puzzles within puzzle rooms
        
        bool checkIfReal();
        //helps to tell the room if there's an actual item in there
};

#endif
