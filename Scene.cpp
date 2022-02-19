#include "Scene.h"

Scene::Scene(){
    wall = Wall(150,900,10,150,1500);
}

Scene::~Scene(){
    ;
}

Wall Scene::getWall(){
    return wall;
}

void Scene::rotate(double angle){
    wall.rotate(angle);
}

void Scene::translate(double x, double z){
    wall.translate(x,z);
}