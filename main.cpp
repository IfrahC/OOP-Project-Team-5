#include "game.hpp"
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
int main(int argc, char** argv) {
    Game game(WIN_WIDTH, WIN_HEIGHT);
    game.runGameLoop();

    return EXIT_SUCCESS;
}
