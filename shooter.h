#ifndef SHOOTER_H
#define SHOOTER_H
#include "object.h"
#include "bullet.h"

class Shooter:public Object
{
public:
    Shooter(double x,double y,int flag);
    ~Shooter(){};
    void paintShooter(QPainter *p);
    string getType(){return this->type;}
    int getPrice(){return this->price;}
    int getBonus(){return this->bonus;}
    void initBullet(double x,double y,int flag);
    void BulletMove();
    void paintBullet(QPainter *p);
    double getRadius(){return this->radius;}
    bool ifhasShoot(){return this->hasShoot;}
    double getBulletX(){return this->_bullet->getX();}
    double getBulletY(){return this->_bullet->getY();}
    void deleteBullet();
    int getMinus(){return this->minuslife;}
    bool ifgetTarget(){return this->_bullet->ifGetTarget();}
    int target;//目标敌人编号
    int flag=0;//发射子弹的时间差设置
private:
    QImage image;
    int price;
    int bonus;
    double radius;
    string type;
    Bullet *_bullet;
    bool hasShoot;
    int minuslife;
};

#endif // SHOOTER_H
