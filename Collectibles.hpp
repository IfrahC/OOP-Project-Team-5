#pragma once
#ifndef COLLECTIBLES_HPP
#define COLLECTIBLES_HPP

#include <SDL.h>
#include "Texture.hpp"
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Score.hpp"

class Collectible {
public:
    virtual void collect(Score &score) = 0; // Pure virtual function, 
    virtual void show(); 
    virtual ~Collectible(); //destructor
};

class Coin : public Collectible {
public:
    Coin();
    void collect(Score &score); //increment 2 in the overall score
    void show();
};

class Diamond : public Collectible {
public:
    Diamond();
    void collect(Score &score); //incrememt 5 in the overall score
    void show();
    
};
#endif // COLLECTIBLES_HPP
