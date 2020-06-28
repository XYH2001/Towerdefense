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
    Enemy(int flag,int game);
    ~Enemy(){}
    double getNextX(int flag);
    double getNextY(int flag);
    void move(int flag);
    void paintEnemy(QPainter *p);
    int getBonus(){return this->bonus;}//���˱�������õĽ�ҽ���
    void setlife(int l){this->currentlife -= l;}//���˱�����ʱ����������
    int getCurrentLife(){return this->currentlife;}//���˵�ǰ����ֵ
private:
    QImage image;
    int life;
    int currentlife;
    int bonus;
    double speed;
};

#endif // ENEMY_H
