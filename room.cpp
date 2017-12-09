//Author: Aaron Nicanor
#include <string>
#include <iostream>
#include "room.h"
#include "item.h"

using namespace std;

bool room::finalRoom(){
    
    if (endgameRoom == true){

        return true;

    }else{
        
        return false;

    }
}

bool room::hasExit(char input){

    bool answer = false;
    
    if( input=='n' || input=='N' ){
        
        if(north==true){
            
            answer = true;
        
        }
    
    }else if( input=='e' || input=='E' ){
        
        if(east==true){
            
            answer = true;
        
        }
    
    }else if( input=='s' || input=='S' ){
        
        if(south==true){
                    
        }
    
    }else if( input=='w' || input=='W' ){
        
        if(west==true){
            
            answer = true;
    
        }
    
    }

}

room room::changeRoom(char input){

    room selected;
    
    if( input=='n' || input=='N' ){

        selected = nRoom;

    }else if( input=='e' || input=='E' ){

        selected = eRoom;

    }else if( input=='s' || input=='S' ){

        selected = sRoom;

    }else if( input=='w' || input=='W' ){

        selected = wRoom;

    }

    
    return selected;
}

int room::getID(){
    
    return ID;

}

bool room::puzzleSolver(Item input){

    if(input.puzzleGuess() == ID){
        
        cout<<"The "<<input.name()<<" seems to work!"<<endl;
        return true;
    
    }else{
        
        cout<<"It seems like the "<<input.name()<<" doesn't work in this room..."<<endl;
        return false;
    }

}

void room::removeItem(){
    
    puzzlePiece.checkIfReal() = false;

}

void room::grabItem(item &chosen){
    
    cout<<"You grabbed the "<<puzzlePiece.name()<<" and placed it in your inventory."<<endl;
    chosen = puzzlePiece;
    removeItem();
}

void room::includeItem(bool input){

    real = input;

bool room::checkItem(){
    
    if(puzzlePiece.checkIfReal != false){
        
        return true;
    
    }else(
        
        return false;
    
    }

}

void room::setExits(bool n, bool e, bool s, bool w){

    north = n;
    east = e;
    south = s;
    west = w;

}

void room::setRooms(int connector, char direction){

    if ( direction=='n' ){
        
        nRoom = connector;

    }else if ( direction=='e' ){

        eRoom = connector;

   }else if ( direction=='s' ){

        sRoom = connector;

   }else{

        wRoom = connector;

   }

}

void room::setID(int num);
    
    ID = num;

}

void room::setDesc(string input){

    desc = input;

}

void room::readDesc(){

    cout<<desc<<endl;

}

void room::giveItem(item input){
    
    puzzlePiece = input;

}

void room::setEndgame(){
    
    endgameRoom = true;

}
