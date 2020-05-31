#include "object.h"

Object::Object()
{

}

void Object::initObj(string type){
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load(":pictures/elements.png");

    this->_pict=all.copy(QRect(_icon.getX()*ICON::GRID_SIZE,_icon.getY()*ICON::GRID_SIZE,_icon.getW()*ICON::GRID_SIZE,_icon.getH()*ICON::GRID_SIZE));
}
void Object::show(QPainter *painter){
    int size = ICON::GRID_SIZE;
    painter->drawImage(this->_X*size,this->_Y*size,this->_pict);
}
