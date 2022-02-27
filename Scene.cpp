#include "Scene.h"

Scene::Scene(){
    wall.push_back(Wall(Point(-1,0,1),Point(2,0,1),150,255,0,0));
    //wall.push_back(Wall(Point(4,0,5),Point(8,0,2),150,128,255,0));
    //wall.push_back(Wall(Point(8,0,2),Point(4,0,9),150,0,128,255));
    //wall.push_back(Wall(Point(1600,0,300),Point(400,0,-400),15000));
    //wall.push_back(Wall(Point(400,0,-400),Point(0,0,100),15000));
}

Scene::~Scene(){
    ;
}

Wall Scene::getWall(int i){
    return wall[i];
}

void Scene::rotate(double px, double py, double pz, double angle){
    for(int i{0}; i < wallCount(); ++i){
        wall[i].rotate(px, py, pz, angle);
    }    
}

void Scene::translate(double x, double y, double z){
    for(int i{0}; i < wallCount(); ++i){
        wall[i].translate(x,y,z);
    }
}