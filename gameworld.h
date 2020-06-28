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
#include <QMediaPlayer>
#include <cmath>


class Gameworld//��һ�ؿ�����Ϸ����
{
public:
    Gameworld();
    void initGameworld(string mapFile);//��ʼ����Ϸ����
    void draw(QPainter *painter);
    bool hasObject(double x,double y);
private:
    vector<Object*> _objects;
    QPixmap _pix;
};

#endif // GAMEWORLD_H
