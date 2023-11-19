#pragma once
#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
private:
    int score;

public:
    Score();
    int getscore() const;
    void incrementscore(int n);
};

#endif // SCORE_HPP
