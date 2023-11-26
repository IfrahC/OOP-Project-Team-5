#pragma once
#include <chrono>

class Stopwatch {
public:
    Stopwatch();

    void start(); //starting stopwatch

    void stop(); //stopping stopwatch

    void reset(); //resetting stopwatch

    double elapsed() const; //returns the current time
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    double elapsed_time;
    bool running;
};

