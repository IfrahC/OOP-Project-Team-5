// Player.cpp
#pragma once
#include "Player.hpp"

void Player::addPlayer(SDL_Renderer* renderer, std::string mtexturePath, int x, int y, int width, int height,int mazesize) {
    //storing values based on the values provided
    mover = new SDL_Rect{x, y, width, height};
    texturePath=mtexturePath;
    playertexture.texture=playertexture.load(renderer, texturePath);
    xJump = SCREEN_HEIGHT/mazesize; 
    yJump = SCREEN_HEIGHT/mazesize; 
    curr_x=mazesize-1; //bottomright position start point
    curr_y=mazesize-1;

}

Player::~Player() {
    delete mover;
    mover=nullptr;
}
//moves player using yjump and xjump
void Player::moveSouth() {
    if (mover->y + yJump <= SCREEN_HEIGHT)
        mover->y += yJump;
}

void Player::moveNorth() {
    if (mover->y - yJump >= 0)
        mover->y -= yJump;
    else
        mover->y = 0;
}

void Player::moveEast() {
    if (mover->x + xJump <= SCREEN_WIDTH)
        mover->x += xJump;
}

void Player::moveWest() {
    if (mover->x - xJump >= 0)
        mover->x -= xJump;
}
