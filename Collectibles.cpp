
#include "Collectibles.hpp"
Collectible::~Collectible() = default;
Coin::Coin(){};
Diamond::Diamond(){};

Coin::~Coin() {  }
Diamond::~Diamond() {  }

void Coin::collect(Score &score)
{
      // increments two in the overall score if a coin is collected
      score = score + 2;
}
void Diamond::collect(Score &score)
{
      // increments 5 in the overall score if a diamond is collected
      score = score + 5;
}

void Coin::show() { std::cout << "coin"; }
void Diamond::show() { std::cout << "diamond"; }
void Collectible::show() {}
