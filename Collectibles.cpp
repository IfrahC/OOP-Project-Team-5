#pragma once
#include "Collectibles.hpp"
Collectible::~Collectible()=default;
Coin::Coin(){ };
void Coin::collect(Score &score){
      score.incrementscore(2)  ; //increments two in the overall score if a coin is collected
}
void Diamond::collect(Score &score){
        score.incrementscore(5); //increments 5 in the overall score if a diamond is collected
}

Diamond::Diamond(){};
void Coin::show(){std::cout<<"coin";}
void Diamond::show(){std::cout<<"diamond";}
void Collectible::show(){}
