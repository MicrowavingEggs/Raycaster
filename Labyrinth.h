#ifndef Labyrinth_h
#define Labyrinth_h

class Labyrinth {
    private :
        int height;
        int width;
    
    public:
        Labyrinth();
        Labyrinth(int h, int w);
        ~Labyrinth();
        int getHeight();
        int getWidth();

};


#endif /* Labyrinth_h */