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
    int getPrice(){return this->price;}//种植射手所需金币数
    int getBonus(){return this->bonus;}//拆除炮塔获得金币数
    void initBullet(double x,double y,int flag);//初始化子弹
    void BulletMove();
    void paintBullet(QPainter *p);
    double getRadius(){return this->radius;}//子弹攻击范围
    bool ifhasShoot(){return this->hasShoot;}//判断炮塔此时是否有子弹
    double getBulletX(){return this->_bullet->getX();}
    double getBulletY(){return this->_bullet->getY();}
    void deleteBullet();//删除子弹
    int getMinus(){return this->minuslife;}//攻击后敌人减少的生命值
    bool ifgetTarget(){return this->_bullet->ifGetTarget();}//判断子弹是否到达目标点
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
