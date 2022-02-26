#ifndef Point_h
#define Point_h
#include "math.h"

class Point {
    private:
        double x;
        double y;
        double z;
    
    public:
        Point();
        Point(double px, double py, double pz);
        ~Point();
        double getX();
        double getY();
        double getZ();
        void setX(double px);
        void setY(double py);
        void setZ(double pz);
        void translate(double dx, double dy, double dz);
        void rotate(double px, double py, double pz, double angle);
};


#endif /* Point_h */