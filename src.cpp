#include <iostream>

#include "def.hpp"
#include "ghosts.cpp"

 game Game;

short board[board_X][board_Y];

void boardStart(){
    for(int TopLine = 0; TopLine < board_X; TopLine++){
        board[TopLine][0] = wall;
        board[TopLine][board_Y-1] = wall;
    }
}

int indexBoard(int X, int Y, int value){
    
    if(X > board_X || Y > board_Y){return invalid;}

    if(value == NA){return board[X][Y];}
    
        board[X][Y] = value;
}

void printBoard(){
    for(int Y = 0; Y < board_Y; Y++){
        for(int X = 0; X < board_X; X++){
            std::cout<<board[X][Y];
        }
        std::cout<<"\n";
    }
}


void game::spawnPlayer(){board[spawnX][spawnY]=player;}


int main(){
    system("clear");

    boardStart();

   Game.spawnPlayer();
    printBoard();
}