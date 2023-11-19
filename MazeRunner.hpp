#pragma once
#include<iostream>
#include<string>
#include "Cell.hpp"
#include "Score.hpp"
#include "Maze.h"
#include "game.hpp"
#include "Player.hpp"
using namespace std;

extern Score score;
extern string gameState;

std::string makeMove(string direction,Maze* generator,Player& boy,Score& points,std::string gameState);
