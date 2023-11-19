#pragma once
#include "Collectibles.hpp"
Collectible::~Collectible()=default;
Coin::Coin(){ };
void Coin::collect(Score &score){
      score.incrementscore(2)  ;
}
void Diamond::collect(Score &score){
        score.incrementscore(5);
}

Diamond::Diamond(){};
void Coin::show(){std::cout<<"coin";}
void Diamond::show(){std::cout<<"diamond";}
void Collectible::show(){}
