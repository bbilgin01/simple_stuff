#Project Name

project(Mazer)

set(CMAKE_CXX_STANDARD 23)
SET (CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mazer_game
               mazer_main.cpp
               maze.cpp
               player.cpp)               
