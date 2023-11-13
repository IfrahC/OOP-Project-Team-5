

#include "include/SDL2/SDL.h"


#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


class Cell {
    public:
    Cell();
    const Cell& operator=(const Cell&);
    std::string direction(const Cell&);
    std::string directionopposite(std::string direct);
    void drawCell(SDL_Color color); //draws the cell
    bool eastwalls;
    bool westwalls;
    bool northwalls;
    bool southwalls;
    int x; //x,y represents the position of cell in the maze when it will be generated. it is based on the scale
    int y;
    int i; //i,j represent the index of cell in the grade
    int j;
    int scale;
    bool visited;
    SDL_Renderer* renderer;
    
    
};



