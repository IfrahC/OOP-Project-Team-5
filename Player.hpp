// Player.hpp
#pragma once
#include "Texture.hpp"
#include <iostream>
#include <SDL.h>
#include <string>
#include "Maze.hpp"

class Player
{
public:
    void addPlayer(SDL_Renderer *renderer, std::string mtexturePath, int x, int y, int width, int height, int scale);
    ~Player();
    Player() = default;
    // move functions for player
    void moveSouth();
    void moveNorth();
    void moveEast();
    void moveWest();
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;

    std::string texturePath;

    SDL_Rect mover;
    Texture playertexture; // texture for player
    int xJump, yJump;      // scale for how much the player is to be moved
    int curr_x;            // current x and y positions
    int curr_y;
    bool &operator==(Coin c);
};
