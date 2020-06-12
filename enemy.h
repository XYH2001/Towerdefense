#ifndef ENEMY_H
#define ENEMY_H
#include "object.h"
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QImage>

class Enemy:public Object
{
public:
    Enemy();
    ~Enemy(){}
    double getNextX();
    double getNextY();
    void move();
    void paintEnemy(QPainter *p);
private:
    int life;
    QImage image;
    static double speed;
};

#endif // ENEMY_H
