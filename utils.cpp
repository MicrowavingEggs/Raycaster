#ifndef utils_cpp
#define utils_cpp

#include "math.h"
#include "Point.h"

static double norm(Point vec){
    double x{vec.getX()};
    double y{vec.getY()};
    double z{vec.getZ()};
    return sqrt(x*x + y*y + z*z);
}

static double dotProduct(Point vec1, Point vec2){
    return vec1.getX()*vec2.getX() + vec1.getY()*vec2.getY() + vec1.getZ()*vec2.getZ();
}

static Point crossProduct(Point vec1, Point vec2){
    double x1{vec1.getX()};
    double y1{vec1.getY()};
    double z1{vec1.getZ()};
    double x2{vec2.getX()};
    double y2{vec2.getY()};
    double z2{vec2.getZ()};
    return Point(y1*z2-z1*y2,z1*x2-x1*z2,x1*y2-y1*x2);
}

static double getAngle(Point vec1, Point vec2){
    return acos(dotProduct(vec1,vec2)/norm(vec1)*norm(vec2));
}


static bool isInFov(Point vecPlayer,Point vecToDraw, double fov){
    return abs(getAngle(vecPlayer,vecToDraw) < fov/2.);
}

#endif /* utils_cpp */