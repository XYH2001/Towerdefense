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
    double getNextX();//��ȡ�ӵ���һʱ���λ��
    double getNextY();
    void paintbullet(QPainter *p);
    void move();
    double getX(){return this->_x;}
    double getY(){return this->_y;}
    bool ifGetTarget();//�ж��ӵ��Ƿ񵽴�Ŀ���
private:
    static double speed;
    double _x,_y;//���ĵ�����
    double tar_x,tar_y;//Ŀ�������
    QImage image;//�ӵ���Ӧͼ��
    double t_cos,t_sin;//�ӵ��������Ŀ�������߽Ƕȵ�cos��sin
};

#endif // BULLET_H
