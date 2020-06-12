#include "enemy.h"
double Enemy::speed=0.5;
#include <math.h>
#include<iostream>
using namespace std;

Enemy::Enemy()
{
    this->_X=0;
    this->_Y=3;
    QImage elem;
    elem.load(":/pictures/elements.png");
    this->image=elem.copy(QRect(7*64,4*64,1*64,1*64));
}
double Enemy::getNextX(){
    if(this->_X<9){
        return this->_X+speed;
    }
    else if(fabs(this->_X-9)<1E-6 && this->_Y<8){
        return this->_X;
    }
    else if(fabs(this->_Y-8)<1E-6){
        return this->_X+speed;
    }
}
double Enemy::getNextY(){
    if(this->_X<9 && fabs(this->_Y-3)<1E-6){
        return this->_Y;
    }
    else if((fabs(this->_X-9)<1E-6) && (this->_Y<8)){
        return this->_Y+speed;
    }
    else if(fabs(this->_Y-8)<1E-6){
        return this->_Y;
    }
}
void Enemy::move(){
    this->_X=this->getNextX();
    this->_Y=this->getNextY();
}
void Enemy::paintEnemy(QPainter *p){
    p->drawImage(this->_X*64,this->_Y*64,this->image);
}
