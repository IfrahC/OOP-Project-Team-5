#pragma once
#include "Cell.hpp"


Cell::Cell() //cell constructor
 {
    
    eastwalls=true;
    westwalls=true;
    northwalls=true;
    southwalls=true;
    visited=false;
    haveCoin=false;
    haveDiamond=false;
    

    
}
Cell::Cell( const Cell& c){ //cell copy constructor
    x = c.x;
    y = c.y;
    i=c.i;
    j=c.j;
    visited = c.visited;
    eastwalls=c.eastwalls;
    westwalls=c.westwalls;
    northwalls=c.northwalls;
    southwalls=c.southwalls;
    haveCoin=c.haveCoin;
    haveDiamond=c.haveDiamond;
}
Cell::~Cell(){ //cell destructor, releasing dynamic memory
    
    delete collectible;
collectible=nullptr;}

const Cell* Cell::operator=(const Cell& c) { //equality overload
    x = c.x;
    y = c.y;
    i=c.i;
    j=c.j;
    visited = c.visited;
    eastwalls=c.eastwalls;
    westwalls=c.westwalls;
    northwalls=c.northwalls;
    southwalls=c.southwalls;
    haveCoin=c.haveCoin;
    haveDiamond=c.haveDiamond;
   
    return this;
}

std::string Cell::direction(const Cell& other) { //returns the direction of the other cell with respect to the cell through which it is called
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

std::string Cell::directionopposite(std::string direct) { //returns opposite of the direction passed
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

void Cell::drawCell() { //draws the walls around the cells according to the size of the maze using the scale
    //hwalls represent horizontal walls and vwalls represent vertical walls
    SDL_SetRenderDrawColor(this->renderer, 255 ,255, 255, 0);
    if (vwall.texture==nullptr || hwall.texture==nullptr){std::cout<<"Error";}
    if(eastwalls==true){
        SDL_Rect dst1={x+scale,y,7,scale};
    
        
        SDL_RenderCopy(renderer, this->vwall.texture,nullptr,&dst1 );
       

    }
    if(westwalls==true){
       if (x==0 & y==0){}else{ //condition for opening the destination wall
        SDL_Rect dst2={x,y,7,scale};
  
        SDL_RenderCopy(renderer, this->vwall.texture, nullptr,&dst2);
       
        }
    }
    if(northwalls==true){
   
          SDL_Rect dst3={x,y,scale,7};
    
        SDL_RenderCopy(renderer, this->hwall.texture, nullptr,&dst3);
     
    }
    if(southwalls==true){
       
        SDL_Rect dst4={x,y+scale,scale,7};
        SDL_RenderCopy(renderer, this->hwall.texture, nullptr,&dst4);
    
    }
}
void Cell::loadtexture(){ //function to load textures for walls and collectibles
      this->coinimg.texture = this->coinimg.load(renderer, "Coin.png");
    this->diamondimg.texture = this->diamondimg.load(renderer, "Diamond.png");
     this->vwall.texture = this->vwall.load(renderer, "vwall.png");
    this->hwall.texture = this->hwall.load(renderer, "hwall.png");
}
void Cell::drawCollectible(){ //draw collectibles 
    
    
    if (haveCoin==true){
      
        SDL_Rect dst1={x+10,y+10,scale-15,scale-15};
       SDL_RenderCopy(renderer, this->coinimg.texture,nullptr,&dst1 );
      
    }
    else if (haveDiamond==true){
  
        SDL_Rect dst1={x+10,y+10,scale-15,scale-15};
         SDL_RenderCopy(renderer, this->diamondimg.texture,nullptr,&dst1 );
       
    }
  
}
