#include "Ray.h"
#include "utils.cpp"
#include "math.h"

Ray::Ray(){

}

Ray::Ray(Point p, double a, double rg){
    pos = p;
    angle = a;
    range = rg;
}

Ray::~Ray(){

}

double Ray::getIntersection(Wall wall){
    double x1{pos.getX()};
    double x2{x1 + range*cos(angle)};
    double x3{wall.getX1()};
    double x4{wall.getX2()};
    double z1{pos.getZ()};
    double z2{z1 + range*sin(angle)};
    double z3{wall.getZ1()};
    double z4{wall.getZ2()};
    double denom{(x1-x2)*(z3-z4) - (z1-z2)*(x3-x4)};
    double t{((x1-x3)*(z3-z4) - (z1-z3)*(x3-x4))/denom};
    double u{((x1-x3)*(z1-z2) - (z1-z3)*(x1-z2))/denom};
    if ((0 <= t <= 1) && (0 <= u <= 1)){
        Point Intersection{Point(x3 +u*(x4-x3),0,z3 + u*(z4-z3))};
        return dist(pos,Intersection);
    }
    else{
        return -1.;
    }
}