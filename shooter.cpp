#include "shooter.h"

Shooter::Shooter(double x,double y,int flag)//初始化射手初始坐标,flag为标识，10，20，30，11，21，31分别对应三种炮塔和升级后的炮塔
{
    this->_X=x;
    this->_Y=y;
    this->hasShoot=false;
    this->target=0;
    QImage elem;
    elem.load(":/pictures/elements.png");
    if(flag==10){
        this->type="shooter10";
        this->image=elem.copy(QRect(4*64,4*64,1*64,1*64));
        this->price=200;
        this->bonus=100;
        this->radius=2;
        this->minuslife=1;
    }
    else if(flag==11){
        this->type="shooter11";
        this->image=elem.copy(QRect(13*64,5*64,1*64,1*64));
        this->price=300;
        this->bonus=150;
        this->radius=2.5;
        this->minuslife=2;
    }
    else if(flag==20){
        this->type="shooter20";
        this->image=elem.copy(QRect(15*64,5*64,1*64,1*64));
        this->price=300;
        this->bonus=150;
        this->radius=2.5;
        this->minuslife=1;
    }
    else if(flag==21){
        this->type="shooter20";
        this->image=elem.copy(QRect(3*64,4*64,1*64,1*64));
        this->price=420;
        this->bonus=210;
        this->radius=3;
        this->minuslife=2;
    }
    else if(flag==30){
        this->type="shooter30";
        this->image=elem.copy(QRect(14*64,5*64,1*64,1*64));
        this->price=450;
        this->bonus=225;
        this->radius=3.5;
        this->minuslife=2;
    }
    else if(flag==31){
        this->type="shooter31";
        this->image=elem.copy(QRect(2*64,4*64,1*64,1*64));
        this->price=550;
        this->bonus=275;
        this->radius=5;
        this->minuslife=3;
    }
}
void Shooter::paintBullet(QPainter *p){
    this->_bullet->paintbullet(p);
}
void Shooter::BulletMove(){
    this->_bullet->move();
}
void Shooter::deleteBullet(){//删除子弹，将hasShoot重置为false
    delete this->_bullet;
    this->hasShoot=false;
}
void Shooter::paintShooter(QPainter *p){
    p->drawImage(this->_X*64,this->_Y*64,this->image);
}
void Shooter::initBullet(double x, double y,int flag){//初始化三种不同炮塔的不同子弹类型，同时将hasShoot置为true
    if(flag==1){
        _bullet=new Bullet(this->_X+0.5,this->_Y+0.5,1,x,y);
        this->hasShoot=true;
    }
    else if(flag==2){
        _bullet=new Bullet(this->_X+0.5,this->_Y+0.5,2,x,y);
        this->hasShoot=true;
    }
    else if(flag==3){
        _bullet=new Bullet(this->_X+0.5,this->_Y+0.5,3,x,y);
        this->hasShoot=true;
    }
}
