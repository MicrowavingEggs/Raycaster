#include "Game.h"
#include "utils.cpp"
#include "Ray.h"

const Uint8* state = SDL_GetKeyboardState(NULL);
double ZOffset{450.};
Game::Game(){
    running = true;
    SCREEN_WIDTH = 1600;
    SCREEN_HEIGHT = 900;
    FPS = 60;
    VAngle = M_PI/((float) (100));
    speed = 2/((float) FPS);
	FOV = 2*M_PI/3.;
    window = SDL_CreateWindow("Rasterizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	player = Entity(Point(0,0,0),100);
    scene = Scene();
	minimapOn = false;
	hitbox = Hitbox(Rectangle(Point(0,0,0),Point(1,0,1)));
}

Game::~Game(){
    while(true){
        break;
    }
}

bool Game::isRunning(){
    return running;
}

bool Game::drawMinimap(){
	return minimapOn;
}

void Game::enableMinimap(){
	minimapOn = true;
}

void Game::disableMinimap(){
	minimapOn = false;
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
		if (player.isHitting(hitbox)){
			scene.disable(2);
		}
		else{
			scene.enable(2);
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
			player.translate(speed*cos(playerAngle),0,speed*sin(playerAngle));
		}

		if (state[SDL_SCANCODE_DOWN])
		{
			player.translate(-speed*cos(playerAngle),0,-speed*sin(playerAngle));
		}

		if (state[SDL_SCANCODE_Q])
		{
			player.translate(speed*sin(playerAngle),0,-speed*cos(playerAngle));
		}

		if (state[SDL_SCANCODE_E])
		{
			player.translate(-speed*sin(playerAngle),0,speed*cos(playerAngle));
		}

		if (state[SDL_SCANCODE_LEFT])
		{
			player.rotate(VAngle);
		}

		if (state[SDL_SCANCODE_RIGHT])
		{
			player.rotate(-VAngle);
		}

		if (state[SDL_SCANCODE_SPACE])
		{
			int playerJumpingState{player.getJumpingState()};
			if (playerJumpingState < 60){
				ZOffset = 450 + 80*cos((M_PI/2.) + 2*M_PI*playerJumpingState/59.);
				player.incrJumpingState();
			}
			else{
				player.resetJump();			
			}
		}
		if (state[SDL_SCANCODE_TAB]){
			if (minimapOn){
				disableMinimap();
			}
			else{
				enableMinimap();
			}
		}
}

void Game::render(){
    // For elt in scene, render it.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
		int countWalls{scene.wallCount()};
		for(int x{0}; x < SCREEN_WIDTH; ++x){
			/*SDL_SetRenderDrawColor(renderer,255,255,0,255);
			SDL_RenderDrawLineF(renderer, x, 0, x, ZOffset);
			SDL_SetRenderDrawColor(renderer,0,0,255,255);
			SDL_RenderDrawLineF(renderer, x, ZOffset, x, SCREEN_HEIGHT); */
			Point playerPos{player.getPos()};
			double rayAngle{(FOV/2.)*(1-(2*x/((float) SCREEN_WIDTH-1))) + player.getAngle()};
			Ray ray{Ray(playerPos,rayAngle,100)};
			bool rayHit{false};
			double minDist = 150.; // TODO : à améliorer : prendre min_dist tq min_dist = +inf
			int wallToDraw;
			for(int i{0}; i < countWalls; ++i){
				double tempDist{ray.getIntersection(scene.getWall(i))};
				if (0.01 < tempDist && tempDist <= 100 && tempDist < minDist){
						rayHit = true;
						minDist = tempDist;
						wallToDraw = i;
				}
			}
			if(rayHit){
				Wall wall{scene.getWall(wallToDraw)};
				double height{wall.getHeight()/minDist};
				SDL_SetRenderDrawColor(renderer,wall.getR()/minDist < wall.getR() ? wall.getR()/minDist : wall.getR(), wall.getG()/minDist < wall.getG() ? wall.getG()/minDist : wall.getG(), wall.getB()/minDist < 255 ? wall.getB()/minDist : wall.getB(), 255/minDist < 255 ? 255/minDist : 255);
				SDL_RenderDrawLineF(renderer,x,ZOffset - height/2.,x,ZOffset + height/2.);
				//SDL_SetRenderDrawColor(renderer,255,255,255,255);
				//SDL_RenderDrawLineF(renderer,800 + playerPos.getX(),450 - playerPos.getZ(),800 + playerPos.getX() + 100*cos(rayAngle+player.getAngle()), 450 - playerPos.getZ() + 100*sin(rayAngle+player.getAngle()));
			}
		}
		//for(int i{0}; i < scene.wallCount(); ++i){
			//Wall wall = scene.getWall(i);
			//if(isInFov(Point(0,0,1),wall.getP1(),FOV) || isInFov(Point(0,0,1),wall.getP2(),FOV)){ // TODO : fix : the vectors involved in the if condition are incorrect.		
				//double slope = wall.slope();
				//double wallHeight = wall.getHeight();
				//double x1 = wall.getX1();
				//double x2 = wall.getX2();
				//double y1 = wall.ZDepth(x1, slope);
				//double y2 = wall.ZDepth(x2, slope);
				//SDL_SetRenderDrawColor(renderer,(255*i)/5,255 - (255*i)/6,0,255);
				//SDL_RenderDrawLineF(renderer, x1,ZOffset + y1/2., x2,ZOffset + y2/2.);
				//SDL_RenderDrawLineF(renderer, x1,ZOffset - y1/2., x2,ZOffset - y2/2.);
				//SDL_RenderDrawLineF(renderer, x1,ZOffset - y1/2., x1,ZOffset + y1/2.);
				//SDL_RenderDrawLineF(renderer, x2,ZOffset - y2/2., x2,ZOffset + y2/2.);
				//double slope2 = (y2-y1)/(x2-x1);
				//if (x1 > x2){
					//for(int x{(int) x2}; x < x1; ++x){
						//double Zdepth{y2 + slope2*(x-x2)};
						//SDL_SetRenderDrawColor(renderer,(255*i)/5,255 - (255*i)/6,0,255);
						//SDL_RenderDrawLineF(renderer, x, ZOffset - Zdepth/2., x, ZOffset + Zdepth/2.);
					//}
				//}
				//else{
					//for(int x{(int) x1}; x < x2; ++x){
						//double Zdepth{y1 + slope2*(x-x1)};
						//SDL_SetRenderDrawColor(renderer,(255*i)/5,255 - (255*i)/6,0,255);
						//SDL_RenderDrawLineF(renderer, x, ZOffset - Zdepth/2., x, ZOffset + Zdepth/2.);
					//}
				//}
			//}			
		//}
		if (drawMinimap()){
			for(int i{0}; i < scene.wallCount(); ++i){
				Wall wall = scene.getWall(i);
				if (wall.isEnabled()){
					SDL_SetRenderDrawColor(renderer,0,0,0,255);
					SDL_RenderDrawLineF(renderer,800 - 5*(wall.getX1()), 450 + 5*(wall.getZ1()), 800 - 5*(wall.getX2()), 450 + 5*(wall.getZ2()));
					//Rectangle hitbox = wall.getHitbox().getBox();
					//SDL_RenderDrawLineF(renderer, 800 - hitbox.getP1().getX()/4., 450 + hitbox.getP1().getZ()/4., 800 - hitbox.getP1().getX()/4., 450 + hitbox.getP2().getZ()/4.);
					//SDL_RenderDrawLineF(renderer, 800 - hitbox.getP1().getX()/4., 450 + hitbox.getP2().getZ()/4., 800 - hitbox.getP2().getX()/4., 450 + hitbox.getP2().getZ()/4.);
					//SDL_RenderDrawLineF(renderer, 800 - hitbox.getP2().getX()/4., 450 + hitbox.getP2().getZ()/4., 800 - hitbox.getP2().getX()/4., 450 + hitbox.getP1().getZ()/4.);
					//SDL_RenderDrawLineF(renderer, 800 - hitbox.getP2().getX()/4., 450 + hitbox.getP1().getZ()/4., 800 - hitbox.getP1().getX()/4., 450 + hitbox.getP1().getZ()/4.);
				}
			}
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderDrawLineF(renderer,800 - 5*(player.getPx()),450 + 5*(player.getPz()),800 - 5*(player.getPx()),450 + 5*(player.getPz()));
			if (player.isHitting(hitbox)){
				SDL_SetRenderDrawColor(renderer,255,0,0,255);
				SDL_RenderDrawLineF(renderer,800,450,795,450);
				SDL_RenderDrawLineF(renderer,795,450,795,455);
				SDL_RenderDrawLineF(renderer,795,455,800,455);
				SDL_RenderDrawLineF(renderer,800,455,800,450);
			}
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