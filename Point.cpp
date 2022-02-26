#include "Point.h"

Point::Point(){
    x = 0.;
    y = 0.;
    z = 0.;
}

Point::Point(double px, double py, double pz){
    x = px;
    y = py;
    z = pz;
}

Point::~Point(){

}

double Point::getX(){
    return x;
}

double Point::getY(){
    return y;
}

double Point::getZ(){
    return z;
}

void Point::setX(double px){
    x = px;
}
void Point::setY(double py){
    y = py;
}
void Point::setZ(double pz){
    z = pz;
}

void Point::translate(double dx, double dy, double dz){
    x += dx;
    y += dy;
    z += dz;
}

void Point::rotate(double px, double py, double pz, double angle){
    double tx{x - px};
    double tz{z - pz};
    tx = tx*cos(angle) - tz*sin(angle);
    tz = tx*sin(angle) + tz*cos(angle);
    x = tx;
    z = tz;


}