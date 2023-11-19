#pragma once
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
        }
    }
    std::cout << "Maze constructor" << std::endl;
}

std::vector<std::vector<int>> Maze::get_all_neighbors(int i, int j) {
    std::vector<int> co_ordinates; //make vector here
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
    std::cout<<"Maze gen started"<<std::endl;
    Cell current_cell = grids[0][0];  // Start from the top-left corner
    
    std::stack<Cell> visited_cells; 

    Cell neighbor;
   
    grids[current_cell.i][current_cell.j].visited = true;
 
    visited_cells.push(grids[current_cell.i][current_cell.j]);
 
   while (!visited_cells.empty()) { //while stack is not empty
        current_cell = visited_cells.top();
        visited_cells.pop();
        //std::cout<<current_cell.i<<current_cell.j;

        std::vector<std::vector<int>> neighbors = get_all_neighbors(current_cell.i, current_cell.j); 
        int random_int = 0;
        
        if (!neighbors.empty()) {
            random_int = 0 + std::rand() % neighbors.size();

            visited_cells.push(grids[current_cell.i][current_cell.j]);
            int a = neighbors[random_int][0];
            int b = neighbors[random_int][1];
            neighbor = grids[a][b];
            std::string direction = grids[current_cell.i][current_cell.j].direction(neighbor);
            
            if (direction=="N"){grids[current_cell.i][current_cell.j].northwalls = false;}
            else if (direction=="S"){grids[current_cell.i][current_cell.j].southwalls = false;}
            else if (direction=="W"){grids[current_cell.i][current_cell.j].westwalls = false;}
            else if  (direction=="E"){grids[current_cell.i][current_cell.j].eastwalls = false;}
           
            
            
            std::string direction_neighbor=grids[current_cell.i][current_cell.j].directionopposite(direction);

            if (direction_neighbor=="N"){grids[neighbor.i][neighbor.j].northwalls = false;}
            else if (direction_neighbor=="S"){grids[neighbor.i][neighbor.j].southwalls = false;}
            else if (direction_neighbor=="W"){grids[neighbor.i][neighbor.j].westwalls = false;}
            else if (direction_neighbor=="E"){grids[neighbor.i][neighbor.j].eastwalls = false;}

            grids[a][b].visited = true;
            visited_cells.push(grids[a][b]);
   
        }
    }
    
	
    if (exit_x == gridSize - 1 && exit_y == gridSize- 1) {
        grids[exit_x][exit_y].eastwalls = false;
    }
     
    //this->placeCollectibles();
    for (int i=0; i<gridSize;i++){
		for (int j=0; j<gridSize;j++){
            std::cout<<1;
            if (grids[i][j].collectible==nullptr){std::cout<<2;}
            else{
			grids[i][j].collectible->show();}
		}
	}
   
    
    

}
void Maze::DrawMaze( ){
    std::cout<<"draw";
    for(int x = 0; x < this->gridSize; x++) {
        for (int y = 0; y < this->gridSize; y++) {
            grids[x][y].drawCell( );
        }
    }
    //this->placeCollectibles();
     SDL_RenderPresent(renderer);
}
void Maze::placeCollectibles(){
    std::cout<<"placed";
    int num=gridSize;
    for (int i=0;i<num;i++){
        int x=rand()%gridSize;
        int y=rand()%gridSize;
        if (grids[x][y].haveCoin==false && grids[x][y].haveDiamond==false){
        grids[x][y].haveCoin=true;
        grids[x][y].collectible= new Coin;}
        
        //grids[x][y].drawCollectible();}

        x=rand()%gridSize;
        y=rand()%gridSize;
        if (grids[x][y].haveCoin==false && grids[x][y].haveDiamond==false){
            grids[x][y].haveDiamond=true;
        grids[x][y].collectible= new Diamond;
        
        }
    }
   
    
    
}
void Maze::drawitems(){
    std::cout<<"drawitem";
    for (int i=0;i<gridSize;i++){
        for (int j=0;j<gridSize;j++){
            if (grids[i][j].haveCoin==true || grids[i][j].haveDiamond==true){
                grids[i][j].drawCollectible();
            }
        }
    }
    SDL_RenderPresent(renderer);
}
Maze::~Maze(){std::cout<<"mazedestrct";
}
