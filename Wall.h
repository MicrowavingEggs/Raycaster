#ifndef Wall_h
#define Wall_h

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
        void rotate(double angle);
        double getX1();
        double getX2();
        double getZ1();
        double getZ2();
        double getHeight();
        double slope();
        double ZDepth(double x, double slope);
};

#endif /* Wall_h */