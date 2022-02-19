#include "Wall.h"

Wall::Wall(){

}

Wall::Wall(double px1, double px2, double pz1, double pz2,double h){
    x1 = px1;
    x2 = px2;
    z1 = pz1;
    z2 = pz2;
    height = h;
}

Wall::~Wall(){

}

void Wall::rotate(double angle){
    double tx1;
    double tz1;
    double tx2;
    double tz2;
    tx1 = x1*cos(angle) + z1*sin(angle);
    tz1 = x1*sin(-angle) + z1*cos(angle);
    tx2 = x2*cos(angle) + z2*sin(angle);
    tz2 = x2*sin(-angle) + z2*cos(angle);
    x1 = tx1;
    x2 = tx2;
    z1 = tz1;
    z2 = tz2;
}

void Wall::translate(double x, double z){
    x1 += x;
    x2 += x;
    z1 += z;
    z2 += z;
}

double Wall::getHeight(){
    return height;
}

double Wall::slope(){
    return (z2-z1)/(x2-x1);
}

double Wall::ZDepth(double x, double slope) {
    return height/(z1 + slope*x);
}

double Wall::getX1(){
    return x1;
}
double Wall::getX2(){
    return x2;
}
double Wall::getZ1(){
    return z1;
}
double Wall:: getZ2(){
    return z2;
}