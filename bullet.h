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
    double getNextX();//获取子弹下一时间的位置
    double getNextY();
    void paintbullet(QPainter *p);
    void move();
    double getX(){return this->_x;}
    double getY(){return this->_y;}
    bool ifGetTarget();//判断子弹是否到达目标点
private:
    static double speed;
    double _x,_y;//中心点坐标
    double tar_x,tar_y;//目标点坐标
    QImage image;//子弹对应图像
    double t_cos,t_sin;//子弹诞生点和目标点间连线角度的cos、sin
};

#endif // BULLET_H
