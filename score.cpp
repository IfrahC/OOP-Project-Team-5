#pragma once
#include "Score.hpp"

Score::Score() : score{0} {}

int Score::getscore() const {
    return score;
}
int Score::setscore(int a){
    score=a;
}
void Score::incrementscore(int n) {
    score+=n;
}


