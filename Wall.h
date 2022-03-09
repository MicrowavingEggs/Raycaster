#ifndef Wall_h
#define Wall_h
#include "Point.h"
#include "Hitbox.h"

class Wall {
    private:
        Point P1;
        Point P2;
        double height;
        int R;
        int G;
        int B;
        int alpha;
        bool enabled;

    public:
        Wall();
        Wall(Point P1, Point P2, double h,int r, int g, int b);
        ~Wall();
        void rotate(double px, double py, double pz, double angle);
        void translate(double dx,double dy, double dz);
        Hitbox getHitbox();
        Point getP1();
        Point getP2();
        int getR();
        int getG();
        int getB();
        double getX1();
        double getY1();
        double getZ1();
        double getX2();
        double getY2();
        double getZ2();
        double getHeight();
        double slope();
        double ZDepth(double x, double slope);
        void enable();
        void disable();
        bool isEnabled();
};

#endif /* Wall_h */