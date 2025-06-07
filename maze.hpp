#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

extern int ROWS;
extern int COLS;
extern int trapCount;

extern std::vector<std::vector<char>> grid;
extern std::pair<int,int> playerPos;
extern std::pair<int, int> exitPos;

bool isPathExists(int player_Row, int player_Col, int exit_Row, int exit_Col);
void initMazeWithValidPath();
void printGrid();
#endif //PLAYER_HPP