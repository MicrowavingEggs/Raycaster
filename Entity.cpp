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