// game.hpp
#ifndef GAME_H
#define GAME_H

#include "include/SDL2/SDL.h"
#include "Maze.h"

class Game {
public:
    Game(int winWidth, int winHeight);
    ~Game();

    void runGameLoop();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Maze* generator;
};

#endif // GAME_H

