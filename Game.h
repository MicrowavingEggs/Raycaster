#ifndef Game_h
#define Game_h
#include <SDL2/SDL.h>
#include "Scene.h"
#include "Entity.h"

class Game {
    private :
        SDL_Window *window;
        SDL_Renderer *renderer;
        int FPS;
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
        bool running;
        Scene scene;
        double VAngle;
        double speed;
        Entity player;

    public:
        Game();
        ~Game();
        bool isRunning();
        void handleEvents();
        void update();
        void render();
        void clean();
        int getFPS();
};

#endif /* Game_h */