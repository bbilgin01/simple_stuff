#include <iostream>
#include <cstdlib>
#include <ctime>
#include "maze.hpp"
#include "player.hpp"


using namespace std;


int main(){
    std::cout<< "Enter Grid Size(row,cols): ";
    std::cin >> ROWS >> COLS;
    while(ROWS <10 || COLS < 10){ 
        std::cout<< "Enter greater Grid Size ROW >= 10 and COL >=10\n";
        std::cin >> ROWS >> COLS;
    }

    std::cout << "Enter Trap Count:";
    std::cin >> trapCount;
    int maxTrapCount = ((ROWS-1)*(COLS-1)/2 -6);
    while(trapCount > maxTrapCount){
        std::cout << "Enter Trap Count Less than " << maxTrapCount << "\n";
        std::cin>> trapCount;
    }
    std::cout <<"Movement Keys W, A ,S, D"<<std::endl;
    std::cout << "Upward Key: W" << std::endl;
    std::cout << "Downward Key: S" <<std::endl;
    std::cout << "Left Key: A"<<std::endl;
    std::cout << "Right Key: D" << std::endl;
    initMazeWithValidPath();
    printGrid();
    while(!hasPlayerWon()){
        char input;
        cin>> input;
        movePlayer(input);
        printGrid();
    }
    std::cout << "YOU'VE FOUND THE EXIT GOOD JOB!!";
    return 0;

}