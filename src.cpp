#include <iostream>
#include<cmath>
#include <string>
#include <thread>
#include <chrono>

#include "def.hpp"
#include "pacManBoard.hpp"
#include "ghosts.cpp"

using namespace std::chrono_literals;
 game Game;

void delay(){
    std::this_thread::sleep_for(500ms);
}


short board[board_Y][board_X];

void boardStart(){
   for(int Y = 0; Y < board_Y; Y++){
        for(int X = 0; X < board_X; X++){
            if(refGameBoard[Y][X] == 1){board[Y][X] = wall;}else(board[Y][X]=0);
        }
    }
}

int indexBoard(int X, int Y, int value){
    
    if(X > board_X || Y > board_Y){return invalid;}

    if(value == NA){return board[Y][X];}
    
        board[X][Y] = value;
        
        return 1;
}

void printBoard(){
    for(int Y = 0; Y < board_Y; Y++){
        for(int X = 0; X < board_X; X++){
                if(board[Y][X]!=0){std::cout<<board[Y][X]<<"";}else(std::cout<<" ");
        }
        std::cout<<"\n";
    }
     
}


void game::spawnPlayer(int X, int Y){
    board[Y][X]=player;
    playerlastX = X;
    playerlastY = Y;
    }

void game::deletePlayer(int X, int Y){
    board[playerlastY][playerlastX] = 0;
  
}

void start(){
    system("clear");

    boardStart();

    Game.spawnPlayer(spawnX, spawnY);
}

void inputkey(){
    char c;
while(true){
    
    std::cin>>c;

    switch (c){
        case w:
            Game.rotatePlayer(up);
             break;
        case a:
            Game.rotatePlayer(left);
             break;
        case s:
            Game.rotatePlayer(down);
             break;
        case d:
            Game.rotatePlayer(right);
              break;
         default:   
            break;
        };
        
}
    
}

void nextFrame(){
    system("clear");
    Game.movePlayer();
    printBoard();
    
     Game.test();
}



int main(){
  
    start();

std::thread input (inputkey);
    int i;
    while(i < 100){
       
    nextFrame();
    

    delay();
    i++;
    }


}