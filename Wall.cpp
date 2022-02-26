#include "Wall.h"

Wall::Wall(){

}

Wall::Wall(Point p1, Point p2,double h){
    P1 = p1;
    P2 = p2;
    height = h;
}

Wall::~Wall(){

}

void Wall::rotate(double px, double py, double pz, double angle){
    double tx1{P1.getX() - px};
    double tz1{P1.getZ() - pz};
    double tx2{P2.getX() - px};
    double tz2{P2.getZ() - pz};
    tx1 = tx1*cos(angle) - tz1*sin(angle);
    tz1 = tx1*sin(angle) + tz1*cos(angle);
    tx2 = tx2*cos(angle) - tz2*sin(angle);
    tz2 = tx2*sin(angle) + tz2*cos(angle);
    P1.setX(tx1);
    P2.setX(tx2);
    P1.setZ(tz1);
    P2.setZ(tz2);

    //TODO : remplacer par P.rotate(px,py,pz,angle);
}

void Wall::translate(double x, double y, double z){
    P1.translate(x,y,z);
    P2.translate(x,y,z);
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