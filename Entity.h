#ifndef Entity_h
#define Entity_h

class Entity {
    private:
        int hp;
        double px;
        double py;
        double pz;
    
    public:
        Entity();
        Entity(int HP,double x, double y, double z);
        ~Entity();
        int getHp();
        double getPx();
        double getPx();
        double getPx();
        void setHp();
        void setPx();
        void setPy();
        void setPz();
        void loseHp(int deltaHp);
        bool isDead();
        void move(double deltaX,double deltaY, double deltaZ);
};


#endif /* Player_h */