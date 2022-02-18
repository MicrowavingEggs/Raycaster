#include <SDL2/SDL.h>
#include <stdio.h>
#include "Game.h"


int main(int argc, char** argv){
    Game game{Game()};
    while (game.isRunning())
    {
        game.render();
    }  
    return 0;
}