#include "bullet.h"
double Bullet::speed=10;
//计算(x1,y1),(x2,y2)间的距离
double distance(double x1,double y1,double x2,double y2){
    double d;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    d=sqrt(d);
    return d;
}
//计算(x1,y1),(x2,y2)连线与水平线所成角度的余弦值
double cos(double x1,double y1,double x2,double y2){
    return (x2-x1)/distance(x1,y1,x2,y2);
}
double sin(double x1,double y1,double x2,double y2){
    return (y2-y1)/distance(x1,y1,x2,y2);
}
Bullet::Bullet(double x,double y,int flag,double m,double n)//flag为标志变量，判断初始化哪一种炮塔的子弹，
                                                            //x,y为诞生点的坐标，m,n为目标点的坐标
{
    this->_x=x;
    this->_y=y;
    this->tar_x=m;
    this->tar_y=n;
    this->t_cos=cos(this->_x,this->_y,this->tar_x,this->tar_y);
    this->t_sin=sin(this->_x,this->_y,this->tar_x,this->tar_y);
    QImage elem;
    elem.load(":/pictures/elements.png");
    if(flag==1)
        this->image=elem.copy(QRect(9*64,5*64,1*64,1*64));
    else if(flag==2)
        this->image=elem.copy(QRect(8*64,5*64,1*64,1*64));
    else if(flag==3)
        this->image=elem.copy(QRect(7*64,5*64,1*64,1*64));
}
void Bullet::paintbullet(QPainter *p){
    p->drawImage((this->_x-0.5)*64,(this->_y-0.5)*64,this->image);
}
double Bullet::getNextX(){
    return (this->_x+speed*0.1*this->t_cos);
}
double Bullet::getNextY(){
    return (this->_y+speed*0.1*this->t_sin);
}
void Bullet::move(){
    this->_x=this->getNextX();
    this->_y=this->getNextY();
}
bool Bullet::ifGetTarget(){
    if(distance(this->_x,this->_y,this->tar_x,this->_y)<0.2)
        return true;
    else
        return false;
}
