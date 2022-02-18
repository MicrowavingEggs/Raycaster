#include "Scene.h"

Scene::Scene(){
    wall = Wall(150,900,1,15,500);
}

Scene::~Scene(){
    ;
}

Wall Scene::getWall(){
    return wall;
}