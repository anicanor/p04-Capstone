//Author: Aaron Nicanor
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "enemy.h"

using namespace std;

string enemy::choice(){
    
    int i = (rand() % 9) + 1;
    string decision;
    if(i <= 3){

        decision = "rock";

    }else if(i >= 4 &&  i <= 6){

        decision = "paper";

    }else{
        
        decision = "scissors";

    }
    
    records.push_back(decision);


    return decision;
}

double enemy::winRatio(int gameTotal){
    
    double ratio;
    ratio = wins / gameTotal;
    return ratio;

}

void enemy::recordWin(int &totalGames){
    
    wins++;
    totalGames++;

}

void enemy::initialWins(){
    
    wins = 0;

}

vector <string> enemy::getVector(){
    
    return records;

}
