#include "Wall.h"

Wall::Wall(){

}

Wall::Wall(Point p1, Point p2, Hitbox box, double h){
    P1 = p1;
    P2 = p2;
    hitbox = box;
    height = h;
}

Wall::~Wall(){

}

void Wall::rotate(double px, double py, double pz, double angle){
    P1.rotate(px,py,pz,angle);
    P2.rotate(px,py,pz,angle);
    hitbox.rotate(px,py,pz,angle);
}

void Wall::translate(double dx, double dy, double dz){
    P1.translate(dx,dy,dz);
    P2.translate(dx,dy,dz);
    hitbox.translate(dx,dy,dz);
}

double Wall::getHeight(){
    return height;
}

double Wall::slope(){
    return (P2.getZ()-P1.getZ())/(P2.getX()-P1.getX());
}

double Wall::ZDepth(double x, double slope) {
    double x1{P1.getX()};
    double z1{P2.getZ()};
    if (z1+slope*(x-x1)>0.001){
        return height/(z1 + slope*(x-x1));
    }
    else{
        return 5000;
    }
}

Point Wall::getP1(){
    return P1;
}

Point Wall::getP2(){
    return P2;
}

double Wall::getX1(){
    return P1.getX();
}
double Wall::getY1(){
    return P1.getY();
}
double Wall::getZ1(){
    return P1.getZ();
}
double Wall::getX2(){
    return P2.getX();
}
double Wall::getY2(){
    return P2.getY();
}
double Wall::getZ2(){
    return P2.getZ();
}

Hitbox Wall::getHitbox(){
    return hitbox;
}