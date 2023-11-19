#pragma once
#ifndef MAZE_H
#define MAZE_H
#include "Texture.hpp"
#include "Cell.hpp"
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "Collectibles.hpp"

class Maze {
    public:
   
    Maze(int m_gridSize, int windowWidth, int windowHeight, SDL_Renderer* m_renderer);//constructor 
     std::vector<std::vector< int>> get_all_neighbors(int i, int j); //function to get neighbors of the cell
    void generate_maze(); //function to generate maze based on backtracking algo

    int start_x; // X-coordinate of the starting point 
    int start_y; // Y-coordinate of the starting point

    int exit_x;  // X-coordinate of the exit point
    int exit_y;  // Y-coordinate of the exit point

    int gridSize; //size of maze
    ~Maze();
    std::vector<std::vector<Cell>> grids; //2d vector representing maze grid
    SDL_Renderer* renderer;
    int scale; //The scale determines how much space each cell occupies in both the horizontal and vertical directions based on window size
    void DrawMaze(/*SDL_Color color*/);
    void placeCollectibles();
    void drawitems();
  
};
#endif // MAZE_H

