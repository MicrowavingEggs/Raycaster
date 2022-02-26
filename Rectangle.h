#ifndef Rectangle_h
#define Rectangle_h
#include "Point.h"

class Rectangle {
    private:
        Point P1;
        Point P2;
    
    public:
        Rectangle();
        Rectangle(Point p1, Point p2);
        ~Rectangle();
        Point getP1();
        Point getP2();
        void translate(double dx, double dy, double dz);
        void rotate(double px, double py, double pz, double angle);

};


#endif /* Rectangle_h */