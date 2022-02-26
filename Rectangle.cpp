#include "Rectangle.h"

Rectangle::Rectangle(){
    P1 = Point();
    P2 = Point();
}

Rectangle::Rectangle(Point p1, Point p2){
    P1 = p1;
    P2 = p2;
}

Rectangle::~Rectangle(){

}

Point Rectangle::getP1(){
    return P1;
}

Point Rectangle::getP2(){
    return P2;
}

void Rectangle::translate(double dx, double dy, double dz){
    P1.translate(dx,dy,dz);
    P2.translate(dx,dy,dz);
}

void Rectangle::rotate(double px, double py, double pz, double angle){
    P1.rotate(px,py,pz,angle);
    P2.rotate(px,py,pz,angle);
}
