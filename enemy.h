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
    int getBonus(){return this->bonus;}//敌人被消灭后获得的金币奖励
    void setlife(int l){this->currentlife -= l;}//敌人被攻击时减少生命数
    int getCurrentLife(){return this->currentlife;}//敌人当前生命值
private:
    QImage image;
    int life;
    int currentlife;
    int bonus;
    double speed;
};

#endif // ENEMY_H
