#include "Hitbox.h"

Hitbox::Hitbox(){
    box = Rectangle();
}

Hitbox::Hitbox(Rectangle rect){
    box = rect;
}

Hitbox::~Hitbox(){

}

Rectangle Hitbox::getBox(){
    return box;
}

void Hitbox::translate(double dx, double dy, double dz){
    box.translate(dx,dy,dz);
}

void Hitbox::rotate(double px, double py, double pz, double angle){
    box.rotate(px,py,pz,angle);

}