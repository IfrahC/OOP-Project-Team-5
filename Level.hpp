// Level.h
#pragma once
#ifndef LEVEL_HPP
#define LEVEL_HPP

class Level {
public:
    enum Difficulty {
        Easy,
        Medium,
        Hard
    };

    Level(Difficulty difficulty); //constructor that takes difficulty and assigns maze size
    int getMazeSize() const; //getter for maze size
    void setMazeSize(Difficulty difficulty); //setter
private:
    int mazeSize;
   
};

#endif // LEVEL_HPP
