#ifndef Wall_h
#define Wall_h
#include "Point.h"
#include "Hitbox.h"

class Wall {
    private:
        Point P1;
        Point P2;
        Hitbox hitbox;
        double height;

    public:
        Wall();
        Wall(Point P1, Point P2, Hitbox box, double h);
        ~Wall();
        void rotate(double px, double py, double pz, double angle);
        void translate(double dx,double dy, double dz);
        Hitbox getHitbox();
        Point getP1();
        Point getP2();
        double getX1();
        double getY1();
        double getZ1();
        double getX2();
        double getY2();
        double getZ2();
        double getHeight();
        double slope();
        double ZDepth(double x, double slope);
};

#endif /* Wall_h */