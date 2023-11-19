#pragma once
#include "Score.hpp"

Score::Score() : score{0} {}

int Score::getscore() const {
    return score;
}

void Score::incrementscore(int n) {
    score+=n;
}


