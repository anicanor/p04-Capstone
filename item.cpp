//Author: Aaron Nicanor
#include "item.h"
#include <string>
#include <iostream>

using namespace std;

string item::name(){

    return caller;

}

int item::puzzleGuess(){

    return solveChecker;

}

void item::giveName(string input){

    caller = input;

}

void item::giveID(int input){

    solveChecker = input;

}

bool item::checkIfReal(){
    
    return real;

}
