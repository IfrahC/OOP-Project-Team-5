
// main.cpp
#pragma once
#include "game.hpp"
#include <SDL.h>
#define WIN_WIDTH 800 //screen size
#define WIN_HEIGHT 800
int main(int argc, char** argv) {

    Game game; //initializing the game object
    srand(time(NULL));
    if (!game.init())
    {
        printf("Failed to initialize!\n");
        return 0;
    }

    game.run(); //running the game loop
    game.close(); //closing the game

    return 0;
}
