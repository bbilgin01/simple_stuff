#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "maze.hpp"

bool hasPlayerWon(){
    return playerPos == exitPos;

}


void movePlayer(char Direction){
    int move_row = 0, move_col = 0;

    switch(std::tolower(Direction)){
        case 'w' : move_row = -1; break;
        case 's' : move_row = 1; break;
        case 'a' : move_col = -1; break;
        case 'd' : move_col = 1; break;
        default: std::cout<<"invalid input "<<"\n"; return;
    }
    int nr = playerPos.first + move_row;
    int nc = playerPos.second + move_col;

    if(grid[nr][nc] == '|' || grid[nr][nc] =='-' ){
        std::cout << "You've bumped into wall :D\n";
        return;
    }
    else if(grid[nr][nc] == 'T' ){
        std::cout << "You've Stepped on a TRAP!\n";
        std::exit(1);
    }
    grid [playerPos.first][playerPos.second] = ' ';
    playerPos = {nr, nc};
    grid[nr][nc] =  'P';
}