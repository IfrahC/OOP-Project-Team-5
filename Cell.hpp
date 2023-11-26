#pragma once
#ifndef CELL_HPP
#define CELL_HPP

#include <SDL.h>
#include <SDL_image.h>
#include "Collectibles.hpp"
#include "Texture.hpp"
#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>


using namespace std;

class Cell {
    public:
    Cell(); //cell constructor
    
    const Cell* operator=(const Cell& c); //cell operator overload
    ~Cell(); //cell destructor
    Cell( const Cell& c); //copy constructor
    std::string direction(const Cell& other); //  will return the direction of the other cell
    std::string directionopposite(std::string direct); //returns opposite direction
    void drawCell(); //draws walls of the cells if theye exist
    void drawCollectible(); //draws collectible if a collectible is placed on the cell
    bool eastwalls;   //true if walls exist
    bool westwalls;
    bool northwalls;
    bool southwalls;
    int x; // x y cordinate with respect to the placement on the screen
    int y;
    int i; // i,j values if with respect to grids
    int j;
    int scale; //the same scale used in maze
    bool visited; 
    bool haveCoin;
    bool haveDiamond;
    Collectible* collectible; //collectible  are placed dynamically  either coin or diamond
    SDL_Renderer* renderer;
    Texture vwall; //textures for cell walls and collectibles
    Texture hwall;
    Texture coinimg;
    Texture diamondimg;
    void loadtexture(); //function to load textures
};
#endif // CELL_HPP


