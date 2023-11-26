#pragma once
#ifndef MAZE_HPP
#define MAZE_HPP
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
   
    Maze();//constructor 
    void gridmaker(int m_gridSize, int windowWidth,int windowHeight, SDL_Renderer* m_renderer); //a function populates the grid with cells
    std::vector<std::vector< int>> get_all_neighbors(int i, int j); //function to get neighbors of the cell
    void generate_maze(); //function to generate maze based on backtracking algo

    int start_x; // X-coordinate of the starting point 
    int start_y; // Y-coordinate of the starting point

    int exit_x;  // X-coordinate of the exit point
    int exit_y;  // Y-coordinate of the exit point

    int gridSize; //size of maze
    ~Maze();
    std::vector<std::vector<int>> list; //a list that stores the i,j position of the cells which have either a coin or a diamond
    SDL_Renderer* renderer; 
    std::vector<std::vector<Cell>> grids; //2d vector representing maze grid
    int scale; //The scale determines how much space each cell occupies in both the horizontal and vertical directions based on window size
    void DrawMaze(); //draws the maze by calling draw cell function of cell class
    void placeCollectibles(); //randomly places the coin and diamonds in the grid
    void drawitems(); //draws the randomly placed collectibles using the list
  
};
#endif // MAZE_HPP

