#pragma once
#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
private:
    int score;

public:
    Score();
    int setscore(int a); //setter
    int getscore() const; //getter
    void incrementscore(int n); //increments the score by provided value
};

#endif // SCORE_HPP
