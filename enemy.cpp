#include "enemy.h"
#include <math.h>
#include<iostream>
using namespace std;

Enemy::Enemy(int flag,int game)
{
    this->_X=0;
    this->_Y=2.5;
    this->speed=1.0;
    QImage elem;
    elem.load(":/pictures/elements.png");
    if(game==1){
        if(flag==1){
            this->life=4;
            this->bonus=100;
            this->image=elem.copy(QRect(7*64,4*64,1*64,1*64));
        }
        else if(flag==2){
            this->life=6;
            this->bonus=150;
            this->image=elem.copy(QRect(8*64,4*64,1*64,1*64));
        }
        else if(flag==3){
            this->life=12;
            this->bonus=250;
            this->image=elem.copy(QRect(9*64,4*64,1*64,1*64));
        }
    }
    else if(game==2){
        if(flag==1){
            this->life=12;
            this->bonus=100;
            this->image=elem.copy(QRect(7*64,4*64,1*64,1*64));
        }
        else if(flag==2){
            this->life=24;
            this->bonus=150;
            this->image=elem.copy(QRect(8*64,4*64,1*64,1*64));
        }
        else if(flag==3){
            this->life=24;
            this->bonus=250;
            this->image=elem.copy(QRect(9*64,4*64,1*64,1*64));
        }
    }
    this->currentlife=this->life;
}
double Enemy::getNextX(int flag){
    if(flag==1){
        if(fabs(this->_Y-2.5)<1E-6 || fabs(this->_Y-7.5)<1E-6)
            return this->_X + speed*0.1;
        else
            return this->_X;
    }
    else if(flag==2){
        if(fabs(this->_X-10)<1E-6 && fabs(this->_Y-2.5)<1E-6)
            return this->_X;
        else if(fabs(this->_X-7)<1E-6 && fabs(this->_Y-4.5)<1E-6)
            return this->_X;
        else if(fabs(this->_X-13)<1E-6 && fabs(this->_Y-7.5)<1E-6)
            return this->_X;
        else if(fabs(this->_X-10)<1E-6 && fabs(this->_Y-4.5)<1E-6)
            return this->_X - speed*0.1;
        else if(fabs(this->_X-7)<1E-6 && fabs(this->_Y-7.5)<1E-6)
            return this->_X + speed*0.1;
        else if(fabs(this->_X-13)<1E-6 && fabs(this->_Y-5.5)<1E-6)
            return this->_X + speed*0.1;
        else if(fabs(this->_Y-2.5)<1E-6 || fabs(this->_Y-7.5)<1E-6)
            return this->_X + speed*0.1;
        else if(fabs(this->_Y-5.5)<1E-6 && this->_X>13)
            return this->_X + speed*0.1;
        else if(fabs(this->_Y-4.5)<1E-6)
            return this->_X - speed*0.1;
        else if(fabs(this->_X-10)<1E-6 || fabs(this->_X-7)<1E-6 || fabs(this->_X-13)<1E-6)
            return this->_X;
    }
}
double Enemy::getNextY(int flag){
    if(flag==1){
        if(fabs(this->_X-9)<1E-6)
            return this->_Y + speed*0.1;
        else
            return this->_Y;
    }
    else if(flag==2){
        if(fabs(this->_X-10)<1E-6 && fabs(this->_Y-2.5)<1E-6)
            return this->_Y + speed*0.1;
        else if(fabs(this->_X-7)<1E-6 && fabs(this->_Y-4.5)<1E-6)
            return this->_Y + speed*0.1;
        else if(fabs(this->_X-13)<1E-6 && fabs(this->_Y-7.5)<1E-6)
            return this->_Y - speed*0.1;
        else if(fabs(this->_X-10)<1E-6 && fabs(this->_Y-4.5)<1E-6)
            return this->_Y;
        else if(fabs(this->_X-7)<1E-6 && fabs(this->_Y-7.5)<1E-6)
            return this->_Y;
        else if(fabs(this->_X-13)<1E-6 && fabs(this->_Y-5.5)<1E-6)
            return this->_Y;
        else if(fabs(this->_Y-2.5)<1E-6 || fabs(this->_Y-7.5)<1E-6)
            return this->_Y;
        else if(fabs(this->_Y-5.5)<1E-6 && this->_X>13)
            return this->_Y;
        else if(fabs(this->_Y-4.5)<1E-6)
            return this->_Y;
        else if(fabs(this->_X-10)<1E-6 || fabs(this->_X-7)<1E-6)
            return this->_Y + speed*0.1;
        else if(fabs(this->_X-13)<1E-6)
            return this->_Y - speed*0.1;
    }
}
void Enemy::move(int flag){
    if(flag==1){
        this->_X=this->getNextX(1);
        this->_Y=this->getNextY(1);
    }
    else if(flag==2){
        this->_X=this->getNextX(2);
        this->_Y=this->getNextY(2);
    }
}
void Enemy::paintEnemy(QPainter *p){
    p->drawImage(this->_X*64,this->_Y*64,this->image);
    p->setPen(Qt::SolidLine);
    p->setBrush(Qt::red);
    p->drawRect(this->_X*64+5,this->_Y*64-10,48,5);
    p->setBrush(Qt::green);
    p->drawRect(this->_X*64+5,this->_Y*64-10,this->currentlife*48/this->life,5);
}
