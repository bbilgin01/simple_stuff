#include <iostream>
#include <cstdlib>
#include <ctime>
#include "maze.hpp"
#include "player.hpp"


int main(){
    std::cout<< "Enter Grid Size(row,cols): ";
    std::cin >> ROWS >> COLS;
    std::cout << "Enter Trap Count:";
    std::cin >> trapCount;
    std::cout <<"Movement Keys W, A ,S, D"<<std::endl;
    std::cout << "Upward Key: W" << std::endl;
    std::cout << "Downward Key: S" <<std::endl;
    std::cout << "Left Key: A"<<std::endl;
    std::cout << "Right Key: D" << std::endl;
    while(!hasPlayerWon()){
        char input;
        cin>> input;
        movePlayer(input);
        
    }
    return 0;

}