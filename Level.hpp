// Level.h
#pragma once
#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
    enum Difficulty {
        Easy,
        Medium,
        Hard,
        Hardest
    };

    Level(Difficulty difficulty);
    int getMazeSize() const;

private:
    int mazeSize;
    void setMazeSize(Difficulty difficulty);
};

#endif // LEVEL_H
