//Author: Aaron Nicanor
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "enemy.h"

using namespace std;

double playerWinRatio(int, int);
void playerRecordWin(int&, int&);
bool winningPerson(string, string);
void finalTally(double, double, int, vector<string>, vector<string>);
vector <string> playerRecords;

int main(){
    
    string playerDecision;
    char input;
    int games, playerWins;
    enemy ai;
    ai.initialWins();
    bool endGames;
    games = 0;
    playerWins = 0;

    
    do{
    
        cout<<"(P)lay, see (W)in ratio, (Q)uit"<<endl;
        cin>>input;

        if( input == 'p' || input == 'P' ){
            
            cout<<"Input your choice:"<<endl<<"rock, paper, or scissors?"<<endl<<"(please input it in all lower case)"<<endl;
            cin>>playerDecision; 
            playerRecords.push_back(playerDecision);
            
            if( winningPerson(playerDecision, ai.choice()) == true ){
            
                cout<<"You win!"<<endl;
                playerRecordWin(playerWins, games);

            }else{
                
                cout<<"You lose!"<<endl;
                ai.recordWin(games);

            }

        }else if( input == 'w' || input == 'W' ){
            
            cout<<"Who's win ratio do you want to see?"<<endl<<"mine or enemy"<<endl<<"(please input it in all lower case)"<<endl;
            cin>>playerDecision;

            if( playerDecision == "mine" ){
                
                cout<<"Your win ratio is "<<playerWinRatio(playerWins, games)<<endl;

            }else if( playerDecision == "enemy" ){
                
                cout<<"The enemy's win ratio is "<<ai.winRatio(games)<<endl;

            }else{

                cout<<"I'm sorry, I don't recognize that responce. Try either mine or enemy next time."<<endl;

            }
        
        }else if( input == 'q' || input == 'Q' ){
            
            endGames = true;
            finalTally(playerWinRatio(playerWins, games), ai.winRatio(games), games, playerRecords, ai.getVector());

        }else{

            cout<<"I'm sorry, I don't quite recognize that response. Try either p, w, or q next time."<<endl;

        }

    }while (endGames != true);

    return 0;

}

double playerWinRatio(int pWins, int total){
    
    double ratio;
    ratio = pWins/total;
    return ratio;

}

void playerRecordWin(int &playerWins, int &games){
    
    playerWins++;
    games++;

}

bool winningPerson(string player, string enemy){
    
    if( player == enemy ){

        return true;

    }else if( player == "scissor" && enemy == "paper" ){
        
        return true;

    }else if( player == "rock" && enemy == "scissor" ){
        
        return true;

    }else if( player == "paper" && enemy == "rock" ){
        
        return true;

    }else{
        
        return false;

    }
}

void finalTally(double playerRatio, double enemyRatio, int games, vector<string> player, vector<string> enemy){
    
    ofstream outFile;
    outFile.open("record_books.txt");
    if (outFile.is_open()){
        outFile<<"This rock paper sciccors match ended with the player having a winning ratio of "<< playerRatio <<"."<<endl<<"and the enemy with a ratio of "<<enemyRatio<<"."<<endl<<"In total, the amount of games played were "<<games<<" games in total!"<<endl;
        for(int i = 0; i < games; i++){
            outFile<<"On match "<<i+1<<" you used "<<player[i]<<" and the enemy used "<<enemy[i]<<"."<<endl;
        }
        outFile<<"I hope you come around to play again!"<<endl<<endl;
    }
    outFile.close();

}




