#include "Maze.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

Maze::Maze(int m_gridSize, int windowWidth, int windowHeight, SDL_Renderer* m_renderer) {
    start_x = 0;
    start_y = 0;
    exit_x = m_gridSize - 1;
    exit_y = m_gridSize - 1;
    scale = windowWidth/m_gridSize;
    gridSize=m_gridSize;
    renderer=m_renderer;
    for (int i = 0; i < gridSize; ++i) {
        std::vector<Cell> a;
        grids.push_back(a);
        for (int j = 0; j < gridSize; ++j) {
            
            grids[i].push_back( Cell());
            grids[i][j] .i=i;
            grids[i][j] .j=j;
            grids[i][j] .x=i*this->scale;
            grids[i][j] .y=j*this->scale;
            grids[i][j].scale=this->scale;
            grids[i][j].renderer=this->renderer;
        }
    }
    //constructor
}

std::vector<std::vector<int>> Maze::get_all_neighbors(int i, int j) {
    std::vector<int> co_ordinates; 
    std::vector<std::vector<int>> valid_neighbors;

    if ((i >= 0 && i < gridSize) && (j + 1 >= 0 && j + 1 < gridSize) && (!grids[i][j + 1].visited)) {
        co_ordinates={i,j+1};
        valid_neighbors.push_back(co_ordinates);
    }
    if ((i >= 0 && i < gridSize) && (j - 1 >= 0 && j - 1 < gridSize) && (!grids[i][j - 1].visited)) {
     
        co_ordinates={i,j-1};
        valid_neighbors.push_back(co_ordinates);
    }
    if ((i - 1 >= 0 && i - 1 < gridSize) && (j >= 0 && j < gridSize) && (!grids[i - 1][j].visited)) {

        co_ordinates={i-1,j};
        valid_neighbors.push_back(co_ordinates);
    }
    if ((i + 1 >= 0 && i + 1 < gridSize) && (j >= 0 && j < gridSize) && (!grids[i + 1][j].visited)) {
  
        co_ordinates={i+1,j};
        valid_neighbors.push_back(co_ordinates);
    }

    return valid_neighbors;
}

