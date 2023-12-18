
#include "Score.hpp"

Score::Score() : score{0} {}

int Score::getscore() const
{
    return score;
}
void Score::setscore(int a)
{
    score = a;
}
void Score::incrementscore(int n)
{
    score += n;
}

Score &Score::operator+(int value)
{
    this->incrementscore(value); // Increment the score by the provided value
    return *this;
}
