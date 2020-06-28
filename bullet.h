#ifndef BULLET_H
#define BULLET_H
#include <QPainter>
#include <QImage>
#include <cmath>
#include <iostream>
using namespace std;
class Bullet
{
public:
    Bullet(double x,double y,int flag,double m,double n);
    ~Bullet(){}
    double getNextX();
    double getNextY();
    void paintbullet(QPainter *p);
    void move();
    double getX(){return this->_x;}
    double getY(){return this->_y;}
    bool ifGetTarget();
private:
    static double speed;
    double _x,_y;//中心点坐标
    double tar_x,tar_y;
    QImage image;
    double t_cos,t_sin;
};

#endif // BULLET_H
