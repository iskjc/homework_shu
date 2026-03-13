cmake_minimum_required(VERSION 4.0)
project(MazeSolver)

set(CMAKE_CXX_STANDARD 14)

include_directories(MazeSolver/src/include)

add_executable(MazeSolver
        MazeSolver/src/include/CImg.h
        MazeSolver/src/include/Maze.h
        MazeSolver/src/include/Node.h
        MazeSolver/src/astar.cpp
        MazeSolver/src/dfs.cpp
        MazeSolver/src/gbfs.cpp
        MazeSolver/src/main.cpp
        MazeSolver/src/Maze.cpp
        MazeSolver/src/Node.cpp)
