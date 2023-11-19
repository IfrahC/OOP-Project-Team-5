// Player.hpp
#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL.h>
#include "Texture.hpp"
#include <string>
#include "game.hpp"

class Player {
public:
    void addPlayer(SDL_Renderer* renderer, std::string mtexturePath, int x, int y, int width, int height,int scale);
    ~Player();
    Player()=default;
    void moveSouth();
    void moveNorth();
    void moveEast();
    void moveWest();
    const int SCREEN_WIDTH=800;
    const int SCREEN_HEIGHT=800;

    std::string texturePath;
    SDL_Rect* mover;
    Texture playertexture;
    int xJump, yJump; // Adjust these values according to your game's needs
    int curr_x;
    int curr_y;
};
#endif
