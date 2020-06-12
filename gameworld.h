#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "object.h"
#include "icon.h"
#include <vector>
#include <string>
#include <QPainter>
#include "enemy.h"
#include <QTimer>
#include <QTime>


class Gameworld
{
public:
    Gameworld();
    void initGameworld(string mapFile);
    void draw(QPainter *painter);
    void eraseObj(double x,double y);
private:
    vector<Object> _objects;
    QPixmap _pix;
};

#endif // GAMEWORLD_H
