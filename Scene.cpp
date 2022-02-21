#include "Scene.h"

Scene::Scene(){
    wall.push_back(Wall(0,150,10,40,1500));
    wall.push_back(Wall(150,900,40,150,1500));    
    wall.push_back(Wall(900,1600,150,30,1500));
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