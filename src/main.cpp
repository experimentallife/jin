#include "../include/basic.h"

int main()
{
    Game * const game = new Game();
    game->run();

    delete game;

    return 0;
}