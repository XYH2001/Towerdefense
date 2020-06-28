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
    int getPrice(){return this->price;}//��ֲ������������
    int getBonus(){return this->bonus;}//���������ý����
    void initBullet(double x,double y,int flag);//��ʼ���ӵ�
    void BulletMove();
    void paintBullet(QPainter *p);
    double getRadius(){return this->radius;}//�ӵ�������Χ
    bool ifhasShoot(){return this->hasShoot;}//�ж�������ʱ�Ƿ����ӵ�
    double getBulletX(){return this->_bullet->getX();}
    double getBulletY(){return this->_bullet->getY();}
    void deleteBullet();//ɾ���ӵ�
    int getMinus(){return this->minuslife;}//��������˼��ٵ�����ֵ
    bool ifgetTarget(){return this->_bullet->ifGetTarget();}//�ж��ӵ��Ƿ񵽴�Ŀ���
    int target;//Ŀ����˱��
    int flag=0;//�����ӵ���ʱ�������
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
