#pragma once
#include <queue>
#include <utility>
#include "maze.hpp"


std::vector<std::vector<char>> grid;
std::pair<int, int> playerPos;
std::pair<int, int> exitPos;

bool isPathExists(int pr, int pc, int er, int ec){
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
    q.push({pr,pc});
    visited[pr][pc] = true;
    const int dr[] = {-1,1,0,0};
    const int dc[] = {0,0,-1,1};
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop(); 
        if(r == er && c == ec) return true; 
        

    }
    return false;
}
void initMazeWithValidPath(){

}

void printGrid(){
    for(int r = 0; r < ROWS; r ++){
        for(int c = 0; c < COLS; c++){
            std::cout<<grid[r][c];
        }
        std::cout<<'\n';
    }
}
    
