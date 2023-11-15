// game.hpp
#ifndef GAME_H
#define GAME_H

#include "include/SDL2/SDL.h"
#include "Maze.h"
#include "include/SDL2/SDL_image.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Game {
 
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;

    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;
    // The window renderer
    SDL_Renderer *gRenderer = NULL;

    Maze* generator;
    int mazeSize;
    SDL_Texture* titleTexture;  
    SDL_Texture* mazebgTexture;

public:
    Game(int size);
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
};

#endif // GAME_H

