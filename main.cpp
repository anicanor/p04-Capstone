//Author: Aaron Nicanor
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

//Prototypes
void levelSetUp(room&);
void recordKeeper(string);
void puzzleSolvedRoom(room&);
int main(){
    
    char input;
    bool happyEnd, sadEnd;
    room currentRoom;
    levelSetUp(currentRoom);
    vector <item> inventory;
    cout<<"You awaken in some unknown room. You carry nothing in your possession and have no idea where you are, but task yourself to find an exit from this strange place."<<endl;
    
    do{
        
        if(currentRoom.finalRoom() == true){
            
            cout<<"You dash into the wide open area."<<endl<<"You are free!"<<endl;
            happyEnd = true;

        }else{
        currentRoom.readDesc();
        cout<<"Currently, you can (M)ove to another room, (T)ake an item in a room, (C)heck you inventory, (U)se an item in your inventory, or (Q)uit the game."<<endl;
        cin>>input;
        
        if( input=='m' || input=='M' ){
            
            cout<<"What direction do you wish to go?"<<endl<<"(N)orth, (E)ast, (S)outh, or (W)est?"<<endl;
            cin>>input;
            
            if( currentRoom.hasExit(input)==true ){
                
                currentRoom = currentRoom.changeRoom(input);

            }else{

            }

        }else if( input=='t' || input=='T' ){

            if(currentRoom.checkItem() == true){
                
                item take;
                currentRoom.grabItem(take);
                inventory.push_back(take);
                cout<<"You successfully taken the "<<take.name()<<endl;

            }else{

                cout<<"There's nothing to grab from this room."<<endl;

            }

        }else if( input=='c' || input=='C' ){
            
            if (inventory.size() == 0){
                
                cout<<"Your inventory is empty"<<endl;

            }else{
                
                cout<<"Within your inventory, you have ";
                for(int i = 0; i < inventory.size(); i++){
                    
                    cout<<"the "<<inventory[i].name()<<" ";

                }
                cout<<endl;

           }

       }else if( input=='u' || input=='U' ){

               cout<<"What item would you like to use? (Type the item's name in all lower case letters)"<<endl;
               cin>>input;
               item chosen;
               chosen.includeItem(false);

               for(int i = 0; i < inventory.size(); i++){
                
                    if (input == inventory[i].name()){
                        
                        chosen = inventory[i];
                        chosen.includeItem(true);

                    }
               }

               if (chosen.checkIfReal() == false){
                
                    cout<<"Seems like you don't have that item in your inventory."<<endl;

               }else{

                    if(currentRoom.puzzleSolver(chosen) == true){
                        
                        puzzleSolvedRoom(currentRoom);

                    }
               }
    

        }else if( input=='q' || input=='Q' ){

                sadEnd = true;
                cout<<"You slip on some foreign object on the floor and fall hard onto the floor. Sadly, you don't survive you rather pitiful tumble. This is where you meet your end..."<<endl;

        }
    }

    }while(happyEnd == true || sadEnd == true);
    
    cout<<"Thanks for playing!"<<endl;
}

void levelSetUp(room &startingRoom){

    room one, two, three, four, five, six, seven;
    item smallKey, bucketOfWater;
    //gives the items their names and IDs
    smallKey.giveName("Small Key");
    smallKey.giveID(1);
    bucketOfWater.giveName("Bucket of Water");
    bucketOfWater.giveID(4);
    //sets up exits
    one.setExits(true, false, false, false);
    two.setExits(false, false, true, false);
    three.setExits(false, true, true, true);
    four.setExits(false, true, false, false);
    five.setExits(false, false, false, true);
    six.setExits(true, false, true, false);
    seven.setExits(false, false, false, false);
    //sets up descriptions of rooms
    one.setDesc("It's an empty room with a single door due north. Upon closer inspection of the seemingly barren room, you can see a small key.");
    two.setDesc("You find yourself in a hallway with a locked door due north and the empty room due south. Perhaps that locked doo could be opened with some kind of key...");
    three.setDesc("This room looks like some kind of living room. To your west, there's a small closet and to your east, there's an archway leading to another room. There's also a room due south.");
    four.setDesc("You cram yourself into the rather tight closet. Within it, you see a bucket filled with water. The only exit is to your east.");
    five.setDesc("You step inside a very comfy looking room. To your north you see a fireplace that has been lit. If you look closey, you can see that there's someting behind the fire. There's also an exit to your west.");
    six.setDesc("The room you enter is filled with fresh air. You can see the outside just north from where you are, finally, an escape! Or, if you really find it nice in here, you can always head back south.");
    //gives certain rooms items
    one.giveItem(smallKey);
    four.giveItem(bucketOfWater);
    //connects the rooms
    one.setRooms(two, 'n');
    two.setRooms(one, 's');
    three.setRooms(two, 's');
    three.setRooms(four, 'w');
    three.setRooms(five, 'e');
    four.setRooms(three, 'e');
    five.setRooms(three, 'w');
    six.setRooms(five, 's');
    six.setRooms(seven, 'n');
    //gives rooms IDs
    one.setID(1);
    two.setID(2);
    three.setID(3);
    four.setID(4);
    five.setID(5);
    six.setID(6);
    //sets starting point
    startingRoom = one;
    //sets ending point
    seven.setEndgame();

}

void puzzleSolvedRoom(room &startingRoom){
    
}

void recordKeeper(string input){

}
