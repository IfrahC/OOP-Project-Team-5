// Level.h
#pragma once

#include <iostream>
class Level
{
public:
    enum Difficulty
    {
        Easy,
        Medium,
        Hard
    };
    Level();                 // constructor that takes difficulty and assigns maze size
    int getMazeSize() const; // getter for maze size
    ~Level();
    Level &operator=(Difficulty difficulty);

private:
    int mazeSize;
    void setMazeSize(Difficulty difficulty); // setter
};
