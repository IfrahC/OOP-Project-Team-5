
#pragma once

#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include <SDL.h>
#include "Texture.hpp"
#include <SDL_image.h>
#include "Maze.hpp"
#include "Player.hpp"
#include "Score.hpp"
#include <string>

#include "Music.hpp"



class GameManager {
public:
    GameManager() {}
    
    std::string move(SDL_Renderer* gRenderer, SDL_Keycode key,Texture& mazebgTexture,Maze* generator , Player &boy,Score& points,std::string gameState,Music& coinmusic,Music& bg);

    void update(SDL_Renderer* gRenderer,Texture& mazebgTexture,Maze* generator,Player& boy,Score& points,std::string gameState);


    void renderScore(SDL_Renderer* renderer, const Score& score);



};
#endif // GAMEMANAGER_HPP
