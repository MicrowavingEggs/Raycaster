#include "Game.h"


Game::Game(){
    running = true;
    SCREEN_WIDTH = 1600;
    SCREEN_HEIGHT = 900;
    FPS = 60;
    window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    scene = Scene();
}

Game::~Game(){
    while(true){
        break;
    }
}

bool Game::isRunning(){
    return running;
}
void Game::handleEvents(){

}
void Game::update(){

}
void Game::render(){
    // For elt in scene, render it.
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        int ZOffset{450};
        Wall wall = scene.getWall();
        double slope = wall.slope();
        double x1 = wall.getX1();
        double x2 =wall.getX2();
        double y1 = wall.ZDepth(x1, slope);
        double y2 = wall.ZDepth(x2, slope);
        SDL_RenderDrawLineF(renderer, x1,ZOffset + y1/2., x2,ZOffset + y2/2.);
        SDL_RenderDrawLineF(renderer, x1,ZOffset - y1/2., x2,ZOffset - y2/2.);
        SDL_RenderDrawLineF(renderer, x1,ZOffset - y1/2., x1,ZOffset + y1/2.);
        SDL_RenderDrawLineF(renderer, x2,ZOffset - y2/2., x2,ZOffset + y2/2.);
        SDL_RenderPresent(renderer);
}