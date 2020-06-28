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
    Object(double x,double y);
    void initObj(string type);//初始化物体类型
    void setX(double x){this->_X=x;}
    void setY(double y){this->_Y=y;}
    double getX() const{return this->_X;}
    double getY() const{return this->_Y;}
    double getW() const{return this->_icon.getW();}
    double getH() const{return this->_icon.getH();}
    QImage getImage();
    string getObjType() const{return this->_icon.getTypeName();}
protected:
    QImage _pict;//物体对应图像
    double _X,_Y;
    ICON _icon;
};

#endif // OBJECT_H
