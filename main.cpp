#include "game.hpp"

int main(int argc, char** argv) {

    Game game{20};
    srand(time(NULL));
    if (!game.init())
    {
        printf("Failed to initialize!\n");
        return 0;
    }

    game.run();
    game.close();

    return 0;
}

