#include "Game.h"

const Uint8* state = SDL_GetKeyboardState(NULL);

Game::Game(){
    running = true;
    SCREEN_WIDTH = 1600;
    SCREEN_HEIGHT = 900;
    FPS = 60;
    VAngle = M_PI/(4*(float) 60);
    speed = 20/((float) FPS);
    window = SDL_CreateWindow("Rasterizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
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
    SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
}
void Game::update(){
		// gestion du mouvement
		if (state[SDL_SCANCODE_UP])
		{
			scene.translate(0,-speed);
		}

		if (state[SDL_SCANCODE_DOWN])
		{
            scene.translate(0,speed);
		}

		if (state[SDL_SCANCODE_Q])
		{
            scene.translate(speed,0);
		}

		if (state[SDL_SCANCODE_E])
		{
            scene.translate(-speed,0);
		}

		if (state[SDL_SCANCODE_LEFT])
		{
			scene.rotate(VAngle);
		}

		if (state[SDL_SCANCODE_RIGHT])
		{
			scene.rotate(-VAngle);
		}

		if (state[SDL_SCANCODE_SPACE])
		{

		}
}

void Game::render(){
    // For elt in scene, render it.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
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

void Game::clean(){
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
}

int Game::getFPS(){
    return FPS;
}