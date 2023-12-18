#pragma once

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

class Cell
{
public:
    Cell();                                            // cell constructor
    const Cell *operator=(const Cell &c);              // cell operator overload
    ~Cell();                                           // cell destructor
    Cell(const Cell &c);                               // copy constructor
    void loadtexture();                                // function to load textures
    std::string direction(const Cell &other);          //  will return the direction of the other cell
    std::string directionopposite(std::string direct); // returns opposite direction
    void drawCell();                                   // draws walls of the cells if theye exist
    void drawCollectible();                            // draws collectible if a collectible is placed on the cell

    bool geteastwalls() { return eastwalls; } // getter and setters for bool walls
    void seteastwalls(bool t) { eastwalls = t; }
    bool getwestwalls() { return westwalls; }
    void setwestwalls(bool t) { westwalls = t; }
    bool getsouthwalls() { return southwalls; }
    void setsouthwalls(bool t) { southwalls = t; }
    bool getnorthwalls() { return northwalls; }
    void setnorthwalls(bool t) { northwalls = t; }
    void seti(int mi) { i = mi; } // setters for i,j,x,y
    void setj(int mj) { j = mj; }
    void setx(int mx) { x = mx; }
    void sety(int my) { y = my; }
    int geti() { return i; } // getters for i,j,x,y
    int getj() { return j; }
    int getx() { return x; }
    int gety() { return y; }

    void setscale(int a) { scale = a; }
    bool getvisited() { return visited; }
    void setvisited(bool m) { visited = m; }
    bool haveCoin;
    bool haveDiamond;
    Collectible *collectible; // collectible  are placed dynamically  either coin or diamond
    SDL_Renderer *renderer;
    bool & operator==(Diamond d);
    bool & operator==(Coin c);

private:
    Texture vwall; // textures for cell walls and collectibles
    Texture hwall;
    Texture coinimg;
    Texture diamondimg;
    bool eastwalls; // true if walls exist
    bool westwalls;
    bool northwalls;
    bool southwalls;
    int x; // x y cordinate with respect to the placement on the screen
    int y;
    int i; // i,j values if with respect to grids (row,column)
    int j;
    int scale; // the same scale used in maze
    bool visited;
};
