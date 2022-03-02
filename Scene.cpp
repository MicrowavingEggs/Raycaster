#include "Scene.h"

Scene::Scene(){
    wall.push_back(Wall(Point(0,0,0),Point(0,0,5),150,128,128,255));
    wall.push_back(Wall(Point(0,0,0),Point(5,0,0),150,128,128,255));
    wall.push_back(Wall(Point(5,0,0),Point(5,0,5),150,128,128,255));
    wall.push_back(Wall(Point(0,0,5),Point(5,0,5),150,128,128,255));
    wall.push_back(Wall(Point(0,0,1),Point(2,0,1),150,128,128,255));
    wall.push_back(Wall(Point(0,0,2),Point(2,0,2),150,128,128,255));
    wall.push_back(Wall(Point(1,0,3),Point(2,0,3),150,128,128,255));
    wall.push_back(Wall(Point(3,0,1),Point(4,0,1),150,128,128,255));
    wall.push_back(Wall(Point(4,0,3),Point(5,0,3),150,128,128,255));
    wall.push_back(Wall(Point(4,0,4),Point(5,0,4),150,128,128,255));
    wall.push_back(Wall(Point(2,0,1),Point(2,0,2),150,128,128,255));
    wall.push_back(Wall(Point(3,0,0),Point(3,0,1),150,128,128,255));
    wall.push_back(Wall(Point(4,0,0),Point(4,0,1),150,128,128,255));
    wall.push_back(Wall(Point(1,0,3),Point(1,0,5),150,128,128,255));
    wall.push_back(Wall(Point(2,0,3),Point(2,0,4),150,128,128,255));
    wall.push_back(Wall(Point(3,0,3),Point(3,0,5),150,128,128,255));
    wall.push_back(Wall(Point(4,0,3),Point(4,0,4),150,128,128,255));
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