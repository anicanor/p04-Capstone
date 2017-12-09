//Author: Aaron Nicanor
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class enemy{

    private:

        int wins;
        vector <string> records;

    public:

        string choice();
        //Let's the ai randomly choose either rock, paper, or scissors

        double winRatio(int);
        //Shows the ai's win ratio

        void recordWin(int&);
        //Adds a win to the ai's counter

        void initialWins();
        //Makes sure the enemy's win count starts at zero

        vector <string> getVector();
        //returns the vector of strings within the private section of the class


};

#endif
