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
        void rotate(double angle);
        void translate(double x, double z);
};


#endif /* Scene_h */