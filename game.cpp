// game.cpp
#include "game.hpp"
#include <iostream>

Game::Game(int winWidth, int winHeight) {
    window = SDL_CreateWindow("MazeSolver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winWidth, winHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    generator = new Maze(20, winWidth, winHeight, renderer);
    std::cout << "Maze generated" << std::endl;
    generator->generate_maze();
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_Quit();
    delete generator;
    generator = nullptr;
}

void Game::runGameLoop() {
    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT)
            break;
    }
}
