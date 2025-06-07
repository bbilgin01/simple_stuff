#include <iostream>
#include <string>
#include "player.hpp"
#include "maze.hpp"

bool hasPlayerWon(){
    return playerPos == exitPos;
}


void movePlayer(char Direction){
    int move_row, move_col = 0;

    switch(std::tolower(Direction)){
        case 'w' : move_row = -1; break;
        case 's' : move_row = 1; break;
        case 'a' : move_col = -1; break;
        case 'd' : move_col = 1; break;
    }
}