#include "Game.h"

const Uint8* state = SDL_GetKeyboardState(NULL);
double ZOffset{450.};
Game::Game(){
    running = true;
    SCREEN_WIDTH = 1600;
    SCREEN_HEIGHT = 900;
    FPS = 60;
    VAngle = M_PI/((float) (1000));
    speed = 20/((float) FPS);
    window = SDL_CreateWindow("Rasterizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	player = Entity();
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
		double playerAngle = player.getAngle();
		double x = player.getPx();
		double y = player.getPy();
		double z = player.getPz();
		if (state[SDL_SCANCODE_UP])
		{
			scene.translate(-speed,0,-speed);
		}

		if (state[SDL_SCANCODE_DOWN])
		{
			scene.translate(speed,0,speed);
		}

		if (state[SDL_SCANCODE_Q])
		{
			scene.translate(-speed,0,0);
		}

		if (state[SDL_SCANCODE_E])
		{
			scene.translate(speed,0,0);
		}

		if (state[SDL_SCANCODE_LEFT])
		{
			scene.rotate(x,y,z,-VAngle);
		}

		if (state[SDL_SCANCODE_RIGHT])
		{
			scene.rotate(x,y,z,VAngle);
		}

		if (state[SDL_SCANCODE_SPACE])
		{
			int playerJumpingState{player.getJumpingState()};
			if(playerJumpingState < 30){
				ZOffset += speed;
				player.incrJumpingState();
			}
			else if (playerJumpingState < 60){
				ZOffset -= speed;
				player.incrJumpingState();
			}
			else{
				player.resetJump();			
			}
		}
}

void Game::render(){
    // For elt in scene, render it.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
		for(int i{0}; i < scene.wallCount(); ++i){
			Wall wall = scene.getWall(i);
			double slope = wall.slope();
			double x1 = wall.getX1();
			double x2 = wall.getX2();
			double y1 = wall.ZDepth(x1, slope);
			double y2 = wall.ZDepth(x2, slope);
			SDL_RenderDrawLineF(renderer, x1,ZOffset + y1/2., x2,ZOffset + y2/2.);
			SDL_RenderDrawLineF(renderer, x1,ZOffset - y1/2., x2,ZOffset - y2/2.);
			SDL_RenderDrawLineF(renderer, x1,ZOffset - y1/2., x1,ZOffset + y1/2.);
			SDL_RenderDrawLineF(renderer, x2,ZOffset - y2/2., x2,ZOffset + y2/2.);
			//if (x1 > x2){
			//	for(int x{(int) x1}; x < x2; ++x){
			//		double Zdepth = wall.ZDepth(x,slope);
			//		SDL_RenderDrawLineF(renderer, x, ZOffset - Zdepth/2., x, ZOffset + Zdepth/2.);
			//	}
			//}
			//else{
			//	for(int x{(int) x2}; x < x1; ++x){
			//		double Zdepth = wall.ZDepth(x,slope);
			//		SDL_RenderDrawLineF(renderer, x, ZOffset - Zdepth/2., x, ZOffset + Zdepth/2.);
			//	}
			//}

		}
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