#pragma once
#include "Level.hpp"

Level::Level(Difficulty difficulty) {
    setMazeSize(difficulty);
}

int Level::getMazeSize() const {
    return mazeSize;
}

void Level::setMazeSize(Difficulty difficulty) {
    switch (difficulty) {
        case Easy:
            mazeSize = 10;  
            break;
        case Medium:
            mazeSize = 15;  
            break;
        case Hard:
            mazeSize = 20;  
            break;
        case Hardest:
            mazeSize = 25;
            break;

       
    }
}
