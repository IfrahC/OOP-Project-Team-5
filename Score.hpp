#pragma once

class Score
{
private:
    int score;

public:
    Score();
    void setscore(int a);       // setter
    int getscore() const;       // getter
    void incrementscore(int n); // increments the score by provided value
    Score &operator+(int value);
};
