#include <iostream>
#include "collectables.hpp"
#include "Score.cpp"
#include <vector>
using namespace std;

// Define a Collectible class
class Collectible
{
public:
    SDL_Rect position;

    // pure virtual function score incrementation
    virtual int updateScore(Score &score) = 0;

    // Check for collision with the player
    virtual bool checkCollision(SDL_Rect player) = 0;
};

bool Collectible::checkCollision(SDL_Rect player) {
        return SDL_HasIntersection(&position, &player);
    }

class Coin : public Collectible
{
public:
    int updateScore(Score &score) override
    {
        ++score;
    }
};

class Diamond : public Collectible
{
public:
    int updateScore(Score &score) override
    {
        score += 5;
    }
};