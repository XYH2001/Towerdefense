#ifndef OBJECT_H
#define OBJECT_H
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
using namespace std;

class Object
{
public:
    Object();
    Object(int x,int y);
    void initObj(string type);
    void show(QPainter *painter);
    void setX(int x){this->_X=x;}
    void setY(int y){this->_Y=y;}
    int getX() const{return this->_X;}
    int getY() const{return this->_Y;}
    int getW() const{return this->_icon.getW();}
    int getH() const{return this->_icon.getH();}
    int getNextX(int direction);
    int getNextY(int direction);
    //virtual void onErase();
    string getObjType() const{return this->_icon.getTypeName();}
protected:
    QImage _pict;
    int _X,_Y;
    ICON _icon;
};

#endif // OBJECT_H
