#ifndef Wall_h
#define Wall_h
#include "math.h"

class Wall {
    private:
    double x1;
    double x2;
    double z1;
    double z2;
    double height;

    public:
        Wall();
        Wall(double x1,double x2,double z1,double z2,double h);
        ~Wall();
        void rotate(double px, double py, double pz, double angle);
        void translate(double x,double y, double z);
        double getX1();
        double getX2();
        double getZ1();
        double getZ2();
        double getHeight();
        double slope();
        double ZDepth(double x, double slope);
};

#endif /* Wall_h */