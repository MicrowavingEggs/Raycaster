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

void Wall::rotate(double px, double py, double pz, double angle){
    double tx1{x1 - px};
    double tz1{z1 - pz};
    double tx2{x2 - px};
    double tz2{z2 - pz};
    tx1 = tx1*cos(angle) - tz1*sin(angle);
    tz1 = tx1*sin(angle) + tz1*cos(angle);
    tx2 = tx2*cos(angle) - tz2*sin(angle);
    tz2 = tx2*sin(angle) + tz2*cos(angle);
    x1 = tx1;
    x2 = tx2;
    z1 = tz1;
    z2 = tz2;
}

void Wall::translate(double x, double y, double z){
    x1 += x;
    x2 += x;

    //TODO Add y coordinate to wall in class definition first.
    //y1 += y;
    //y2 += y;
    
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
    if (z1+slope*(x-x1)>0.001){
        return height/(z1 + slope*(x-x1));
    }
    else{
        return 5000;
    }
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