#include "Scene.h"

Scene::Scene(){
    wall.push_back(Wall(0,150,100,400,15000));
    wall.push_back(Wall(150,900,400,1500,15000));    
    wall.push_back(Wall(900,1600,1500,300,15000));
    wall.push_back(Wall(1600,400,300,-400,15000));
    wall.push_back(Wall(400,0,-400,100,15000));
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