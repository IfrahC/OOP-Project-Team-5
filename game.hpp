// game.hpp

#pragma once
#include <SDL.h>
  #include <SDL_image.h>
  #include <SDL_ttf.h>

#include "Cell.hpp"
#include "Maze.h"

#include "Texture.hpp"

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Score.hpp"
#ifndef GAME_HPP
#define GAME_HPP
class Game {
 
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;
    Score points;
    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;
    // The window renderer
    SDL_Renderer *gRenderer = NULL;

 
    Maze* generator;
    /*SDL_Texture* titleTexture;  
    SDL_Texture* mazebgTexture;*/
    Texture titleTexture;
    Texture mazebgTexture;
    Texture selectplayer;
    //
    Texture vwall;
    Texture hwall;
    Texture boy;
    Texture girl;
    
public:
    bool init();
    bool loadMedia();
    void close();
   // SDL_Texture *loadTexture(std::string path);
    void run();
};

#endif // GAME_HPP

