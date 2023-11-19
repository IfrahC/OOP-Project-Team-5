
#pragma once
#include <SDL.h>
#include "Texture.hpp"
#include <SDL_image.h>
#include "Maze.h"
#include "game.hpp"
#include "Player.hpp"
#include <string>



void update(SDL_Renderer* gRenderer, Texture mazebgTexture,Maze* generator,Player &boy,Score& points,std::string gameState);
std::string move(SDL_Renderer* gRenderer,  SDL_Keycode key,Texture mazebgTexture,Maze* generator,Player &boy,Score& points,std::string gameState);


