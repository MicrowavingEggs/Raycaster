#include "Entity.h"

Entity::Entity(){
    hp = 100;
    px = 0;
    py = 0;
    pz = 0;
    angle = 0;
    jumpingState = 0;
}

Entity::~Entity(){
    ;
}

double Entity::getPx(){
    return px;
}

double Entity::getPy(){
    return py;
}

double Entity::getPz(){
    return pz;
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

void Entity::move(double deltaX,double deltaY, double deltaZ){
    px += deltaX;
    py += deltaY;
    pz += deltaZ;
}

void Entity::rotate(double deltaAngle){
    angle += deltaAngle;
}