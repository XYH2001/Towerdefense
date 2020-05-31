#include "gameworld.h"
#include "object.h"
#include "icon.h"
#include <iostream>
using namespace std;

Gameworld::Gameworld()
{

}
void Gameworld::initGameworld(string mapFile){
    Object *p1=new Object;
    p1->initObj("shooter");
    p1->setX(2);
    p1->setY(3);
    this->_objects.push_back(p1);
}
void Gameworld::show(QPainter *painter){
    this->_objects[0]->show(painter);
}
