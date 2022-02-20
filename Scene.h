#ifndef Scene_h
#define Scene_h
#include "Wall.h"
#include <vector>

class Scene {
    private :
        std::vector<Wall> wall;

    public :
        Scene();
        ~Scene();
        Wall getWall(int i);
        void rotate(double px, double py, double pz, double angle);
        void translate(double x, double y, double z);
        int wallCount(){
            return wall.size();
        }
};


#endif /* Scene_h */