
#include "Level.hpp"


Level::Level(){}
int Level::getMazeSize() const
{
    return mazeSize;
}

void Level::setMazeSize(Difficulty difficulty)
{
    // setting mazesize based upon the difficulty chosen
    switch (difficulty)
    {
    case Easy:
        mazeSize = 10;
        break;
    case Medium:
        mazeSize = 15;
        break;
    case Hard:
        mazeSize = 20;
        break;
    }
}
Level::~Level() {}
Level& Level::operator=(Difficulty difficulty){
    setMazeSize(difficulty);
}