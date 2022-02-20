#ifndef Entity_h
#define Entity_h

class Entity {
    private:
        int hp;
        double px;
        double py;
        double pz;
        double angle;
        int jumpingState;
    
    public:
        Entity();
        Entity(int HP,double x, double y, double z);
        ~Entity();
        int getHp();
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
        void move(double deltaX,double deltaY, double deltaZ);
        void rotate(double deltaAngle);
};


#endif /* Player_h */