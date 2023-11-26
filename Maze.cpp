#pragma once
#include "Maze.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>


Maze::Maze( ) {

    std::cout << "Maze constructor" << std::endl;
}
void Maze::gridmaker(int m_gridSize, int windowWidth,int windowHeight, SDL_Renderer* m_renderer){
    //the gridmaking function which populates the grid will cells
     start_x = 0;
    start_y = 0;
    exit_x = m_gridSize - 1;
    exit_y = m_gridSize - 1;
    scale = windowWidth/m_gridSize;
    //gridSize=m_gridSize;
     renderer=m_renderer;
     gridSize=m_gridSize;
     grids.resize(gridSize);


    for (int i = 0; i < gridSize; ++i) {
        // Resize each inner vector to have gridSize elements
        grids[i].resize(gridSize);

        for (int j = 0; j < gridSize; ++j) {
            grids[i][j].i = i;
            grids[i][j].j = j;
            grids[i][j].x = i * this->scale;
            grids[i][j].y = j * this->scale;
            grids[i][j].scale = this->scale;
            grids[i][j].renderer = this->renderer;
            grids[i][j].loadtexture();
        }
    }

}

std::vector<std::vector<int>> Maze::get_all_neighbors(int i, int j) {
    //returns a vector of i,j positions of the neighbors of the cell
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


 void Maze::generate_maze() {
    //maze generation function
    Cell *current_cell = &grids[0][0];  // Start from the top-left corner
    //a stack of visited cell pointers
    std::stack<Cell*> visited_cells; 
    //cell pointer for storing the neighbor cell
    Cell* neighbor;
    //marking the current cell visited
    grids[current_cell->i][current_cell->j].visited = true;
    //pushing it into the stack
    visited_cells.push(current_cell);

 
 
   while (!visited_cells.empty()) { //while stack is not empty
        //pop the stack
        current_cell = visited_cells.top();
        visited_cells.pop();
        
        //get all the neigbors of the current cell
        std::vector<std::vector<int>> neighbors = get_all_neighbors(current_cell->i, current_cell->j); 
        int random_int = 0;
        
        if (!neighbors.empty()) { //randomly select the a neighbor from the vector of neigbors
            random_int = 0 + std::rand() % neighbors.size();

            visited_cells.push(current_cell);
            int a = neighbors[random_int][0];
            int b = neighbors[random_int][1];
            neighbor = &grids[a][b];
            //get the direction of the neighbors
            std::string direction = grids[current_cell->i][current_cell->j].direction(*neighbor);
            //breaking wall between the neighbor and the current cell
            if (direction=="N"){grids[current_cell->i][current_cell->j].northwalls = false;}
            else if (direction=="S"){grids[current_cell->i][current_cell->j].southwalls = false;}
            else if (direction=="W"){grids[current_cell->i][current_cell->j].westwalls = false;}
            else if  (direction=="E"){grids[current_cell->i][current_cell->j].eastwalls = false;}
           
            //breaking the wall from the pov of neighbor cell
            std::string direction_neighbor=grids[current_cell->i][current_cell->j].directionopposite(direction);

            if (direction_neighbor=="N"){grids[neighbor->i][neighbor->j].northwalls = false;}
            else if (direction_neighbor=="S"){grids[neighbor->i][neighbor->j].southwalls = false;}
            else if (direction_neighbor=="W"){grids[neighbor->i][neighbor->j].westwalls = false;}
            else if (direction_neighbor=="E"){grids[neighbor->i][neighbor->j].eastwalls = false;}
            //marking the neighbor visited and pushing it into stack
            grids[a][b].visited = true;
            visited_cells.push(neighbor);
   
        }
    }
    
	//opening the wall of the bottomright cell which will be the starting point
    if (exit_x == gridSize - 1 && exit_y == gridSize- 1) {
        grids[exit_x][exit_y].eastwalls = false;
    }
    //calling the place collectible function to place the collectibles randomly
    placeCollectibles();

    

}
//draws the maze(walls) of the generated maze pattern in generatemaze function by calling drawcell function of cell
void Maze::DrawMaze( ){
    
    for(int x = 0; x < this->gridSize; x++) {
        for (int y = 0; y < this->gridSize; y++) {
            grids[x][y].drawCell( );
            
        }
    }
     SDL_RenderPresent(renderer);
}
//randomly places collectibles around the grid
void Maze::placeCollectibles(){
    
    int num=gridSize;
    for (int i=0;i<num;i++){
        int x=rand()%gridSize;
        int y=rand()%gridSize;
        if (grids[x][y].haveCoin==false && grids[x][y].haveDiamond==false){
        grids[x][y].haveCoin=true;
        grids[x][y].collectible= new Coin;}
        //pushing it into the list so that later collectibles could be plaed in appropriate places in the maze through drawitems function
        std::vector<int> a;
        a.push_back(x);a.push_back(y);
        list.push_back(a);
     

        x=rand()%gridSize;
        y=rand()%gridSize;
        if (grids[x][y].haveCoin==false && grids[x][y].haveDiamond==false){
            grids[x][y].haveDiamond=true;
        grids[x][y].collectible= new Diamond;
        std::vector<int> b;
        b.push_back(x);b.push_back(y);
        list.push_back(b);
        }
    }
   
    
    
}
//draw collectibles on the positions stored in list by calling draw collectible function of cell
void Maze::drawitems(){
    for (int i=0; i<list.size();i++)
    {
        grids[list[i][0]][list[i][1]].drawCollectible();
    }
    SDL_RenderPresent(renderer);
}
//destructor
Maze::~Maze(){
}
