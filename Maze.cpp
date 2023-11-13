
#include <string>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>

#define N 12
class Maze {
    public:
    Maze();
    void print_maze();  
    std::vector<std::vector< int>> get_all_neighbors(int i, int j);
    void generate_maze();

    int start_x; // X-coordinate of the starting point
    int start_y; // Y-coordinate of the starting point

    int exit_x;  // X-coordinate of the exit point
    int exit_y;  // Y-coordinate of the exit point

    std::vector<std::vector<Cell>> grids{N, std::vector<Cell>(N)};
};

Maze::Maze() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the fixed starting and exit points
    start_x = 0;
    start_y = 0;
    exit_x = N - 1;
    exit_y = N - 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grids[i][j] = Cell(i, j);
            std::cout<<i<<" "<<j<<std::endl;
        }
    }
}

std::vector<std::vector<int>> Maze::get_all_neighbors(int i, int j) {
    std::vector<int> co_ordinates; //make vector here
    std::vector<std::vector<int>> valid_neighbors;

    if ((i >= 0 && i < N) && (j + 1 >= 0 && j + 1 < N) && (!grids[i][j + 1].visited)) {
        //co_ordinates = std::make_tuple(i, j + 1);
        co_ordinates={i,j+1};
        valid_neighbors.push_back(co_ordinates);
    }
    if ((i >= 0 && i < N) && (j - 1 >= 0 && j - 1 < N) && (!grids[i][j - 1].visited)) {
        //co_ordinates = std::make_tuple(i, j - 1);
        co_ordinates={i,j-1};
        valid_neighbors.push_back(co_ordinates);
    }
    if ((i - 1 >= 0 && i - 1 < N) && (j >= 0 && j < N) && (!grids[i - 1][j].visited)) {
        //co_ordinates = std::make_tuple(i - 1, j);
        co_ordinates={i-1,j};
        valid_neighbors.push_back(co_ordinates);
    }
    if ((i + 1 >= 0 && i + 1 < N) && (j >= 0 && j < N) && (!grids[i + 1][j].visited)) {
       // co_ordinates = std::make_tuple(i + 1, j);
        co_ordinates={i+1,j};
        valid_neighbors.push_back(co_ordinates);
    }

    return valid_neighbors;
}
