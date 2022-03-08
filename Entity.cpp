#include "Entity.h"

Entity::Entity(){
    HP = 100;
    pos = Point();
    angle = 0;
    jumpingState = 0;
}

Entity::Entity(Point p, int hp){
    HP = hp;
    pos = p;
    angle = 0;
    jumpingState = 0;
}

Entity::~Entity(){
    
}

Point Entity::getPos(){
    return pos;
}

double Entity::getPx(){
    return pos.getX();
}

double Entity::getPy(){
    return pos.getY();
}

double Entity::getPz(){
    return pos.getZ();
}

double Entity::getAngle(){
    return angle;
}

int Entity::getJumpingState(){
    return jumpingState;
}

void Entity::incrJumpingState(){
    jumpingState += 1;
}

void Entity::resetJump(){
    jumpingState = 0;
}

void Entity::translate(double dx, double dy, double dz){
    pos.translate(dx,dy,dz);
}

void Entity::rotate(double deltaAngle){
    angle += deltaAngle;
}

bool Entity::isHitting(Hitbox hitbox){
    Rectangle rect{hitbox.getBox()};
    Point P1{rect.getP1()};
    Point P2{rect.getP2()};
    double xmin;
    double xmax;
    double zmin;
    double zmax;
    if (P1.getX() < P2.getX()){
        xmin = P1.getX();
        xmax = P2.getX();
    }
    else{
        xmax = P1.getX();
        xmin = P2.getX();
    }
    if (P1.getZ() < P2.getZ()){
        zmin = P1.getZ();
        zmax = P2.getZ();
    }
    else{
        zmax = P1.getZ();
        zmin = P2.getZ();
    }
    return ((xmin <= pos.getX()) && (pos.getX() <= xmax) && (zmin <= pos.getZ()) && (pos.getZ() <= zmax));
}