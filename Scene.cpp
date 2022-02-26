#include "Scene.h"

Scene::Scene(){
    wall.push_back(Wall(Point(0,0,20),Point(150,0,80),1500));
    wall.push_back(Wall(Point(150,0,80),Point(900,0,240),1500));
    wall.push_back(Wall(Point(900,0,240),Point(1600,0,60),1500));
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