#include "Stopwatch.hpp"
Stopwatch::Stopwatch() : running(false), elapsed_time(0.0) {}
void Stopwatch::start() { //starts the stopwatch
        if (!running) {
            start_time = std::chrono::high_resolution_clock::now();
            running = true;
        }
    }

void Stopwatch::stop() { stops the stopwatch if its running
        if (running) {
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
            elapsed_time += duration.count() / 1000000.0; // convert to seconds
            running = false;
        }
    }
 void Stopwatch::reset() { //resets the elapsedtime to 0
        elapsed_time = 0.0;
    }
  double Stopwatch::elapsed() const { //returns the elapsed time
        if (running) { 
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
            return elapsed_time + duration.count() / 1000000.0; // convert to seconds
        }
        return elapsed_time;
    }
