#include "Cell.h"
Cell::Cell()
 {
    eastwalls=true;
    westwalls=true;
    northwalls=true;
    southwalls=true;
    visited=false;
}

const Cell& Cell::operator=(const Cell& c) {
    x = c.x;
    y = c.y;
    i=c.i;
    j=c.j;
    visited = c.visited;
    eastwalls=c.eastwalls;
    westwalls=c.westwalls;
    northwalls=c.northwalls;
    southwalls=c.southwalls;

    return *this;
}

std::string Cell::direction(const Cell& other) {
    if (i == other.i && j + 1 == other.j)
        return "S";
    if (i == other.i && j- 1 == other.j)
        return "N";
    if (i - 1 == other.i && j == other.j)
        return "W";
    if (i + 1 == other.i && j == other.j)
        return "E";
    return "";
}
std::string Cell::directionopposite(std::string direct) {
    if (direct=="W")
        {return "E";}
    else if (direct=="E")
        {return "W";}
    else if (direct=="S")
        {return "N";}
    else if (direct=="N")
        {return "S";}
    return "";
}
void Cell::drawCell(SDL_Color color) {
    //std::cout<<i<<","<<j<<std::endl;
    // Set render color
    SDL_SetRenderDrawColor(this->renderer, color.r ,color.g, color.b, color.a);

    if(eastwalls==true){
        SDL_RenderDrawLine(this->renderer, x+scale, y, x+scale, y+scale);
    }
    if(westwalls==true){
        SDL_RenderDrawLine(this->renderer, x, y, x, y+scale);
    }
    if(northwalls==true){
        SDL_RenderDrawLine(this->renderer, x, y, x+scale, y);
    }
    if(southwalls==true){
        SDL_RenderDrawLine(this->renderer, x, y+scale, x+scale, y+scale);
    }

    // Render the walls to the screen
    SDL_RenderPresent(this->renderer);
}
