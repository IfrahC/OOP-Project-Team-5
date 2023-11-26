#pragma once
#include<iostream>
#include<string>
#include "Cell.hpp"
#include "Score.hpp"
#include "Maze.hpp"
#include "game.hpp"
#include "Player.hpp"
using namespace std;

//function that deals with the movement of the player
std::string makeMove(string direction,Maze* generator,Player& boy,Score& points,std::string gameState);
