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
    // TODO (rotate the points from  )
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