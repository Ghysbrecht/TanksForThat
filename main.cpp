#include "Game.h"

int main()
{
    Game game;

    while(!game.isFinished()){
        game.run();
    }
}
