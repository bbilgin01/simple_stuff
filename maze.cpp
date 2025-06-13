#include <queue>
#include <utility>
#include <random>
#include "maze.hpp"


std::vector<std::vector<char>> grid;
std::pair<int, int> playerPos;
std::pair<int, int> exitPos;

int ROWS = 10;
int COLS = 10;
int trapCount = 2;

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
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >0 && nr <ROWS-1 && nc > 0 && nc < COLS- 1 && !visited[nr][nc] && grid[nr][nc]!= 'T' && grid[nr][nc]!= '|' && grid[nc][nr]!= '-'){
                visited[nr][nc]= true;
                q.push({nr,nc});
            }
        }
    }
    return false;
}
void initMazeWithValidPath(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> rowDist(1, ROWS-2);
    std::uniform_int_distribution<> colDist(1, COLS-2);
    int wall_count =((ROWS -1)*(COLS-1) /2) - 5;
    while(true){
        grid.assign(ROWS,std::vector<char>(COLS, ' '));
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(r == 0 || r == ROWS-1) grid[r][c] = '-';
                else if(c == 0 || c ==  COLS-1)grid[r][c] = '|';
            }
        }
        playerPos = {rowDist(gen), colDist(gen)};
        exitPos = {rowDist(gen), colDist(gen)};
        while(exitPos ==  playerPos) exitPos = {rowDist(gen), colDist(gen)};
        grid[playerPos.first][playerPos.second] = 'P';
        grid[exitPos.first][exitPos.second] = 'E';

        int placed = 0;
        
        while (placed < trapCount){
            int tr = rowDist(gen);
            int tc = colDist(gen);
            if(tr == playerPos.first && tc  == playerPos.second && tr == exitPos.first && tc ==  exitPos.second)
                continue;
            if(grid[tr][tc] == ' '){
                grid[tr][tc] = 'T';
                placed++;   
            
            } 
        }
        if(isPathExists(playerPos.first, playerPos.second, exitPos.first, exitPos.second))
            break;  
    }
}

void printGrid(){
    for(int r = 0; r < ROWS; r ++){
        for(int c = 0; c < COLS; c++){
            std::cout<<grid[r][c];
        }
        std::cout<<'\n';
    }
}
    
