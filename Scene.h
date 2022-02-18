#ifndef Scene_h
#define Scene_h
#include "Wall.h"

class Scene {
    private :
        Wall wall;

    public :
        Scene();
        ~Scene();
        Wall getWall();
};


#endif /* Scene_h */