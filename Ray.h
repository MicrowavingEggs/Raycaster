#ifndef Ray_h
#define Ray_h
#include "Point.h"
#include "Wall.h"

class Ray {
    private:
        Point pos;
        double angle;
        double range;
    
    public:
        Ray();
        Ray(Point p, double angle, double range);
        ~Ray();
        double getIntersection(Wall wall);
};


#endif /*Ray_h*/