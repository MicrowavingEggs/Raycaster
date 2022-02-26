#ifndef Hitbox_h
#define Hitbox_h
#include "Rectangle.h"

class Hitbox {
    private:
        Rectangle box;
    
    public:
        Hitbox();
        Hitbox(Rectangle rect);
        ~Hitbox();
        Rectangle getBox();
        void translate(double dx, double dy, double dz);
        void rotate(double px, double py, double pz, double angle);
};


#endif /* Hitbox_h */