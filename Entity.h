#ifndef Entity_h
#define Entity_h
#include "Point.h"
#include "Hitbox.h"
#include "Rectangle.h"

class Entity {
    private:
        int HP;
        Point pos;
        double angle;
        int jumpingState;
    
    public:
        Entity();
        Entity(Point p,int hp);
        ~Entity();
        int getHp();
        Point getPos();
        double getPx();
        double getPy();
        double getPz();
        double getAngle();
        int getJumpingState();
        void incrJumpingState();
        void resetJump();
        void setHp();
        void setPx();
        void setPy();
        void setPz();
        void setAngle();
        void loseHp(int deltaHp);
        bool isDead();
        void translate(double deltaX,double deltaY, double deltaZ);
        void rotate(double deltaAngle);
        bool isHitting(Hitbox hitbox);
};


#endif /* Player_h */