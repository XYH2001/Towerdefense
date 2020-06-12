#include "mw2.h"
#include "ui_mw2.h"
#include "mainwindow.h"
#include "icon.h"
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

MW2::MW2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW2)
{
    ui->setupUi(this);
    setFixedSize(1200,744);
    ui->pushButton->setStyleSheet("QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton->move(1000,600);
    ui->pushButton->resize(171,161);

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(EnemyMove()));

    pixmap=new QPixmap(":/pictures/background.png");
    pt=new QPainter(pixmap);
    _game.initGameworld("");
    paintGameworld();
}
MW2::~MW2()
{
    pt->end();
    delete ui;
    delete pixmap;
    delete timer;
    delete pt;
}

void MW2::on_pushButton_clicked(){
    this->hide();
    emit showMainWindow();
}

void MW2::receiveMainWindow(){
    this->show();
    timer->start(1000);
}

void MW2::receiveexit(){
    emit exit();
}
void MW2::paintEvent(QPaintEvent *){
    QPainter *p=new QPainter(this);
    p->drawPixmap(0,0,this->width(),this->height(),*pixmap);
    for(int i=0;i<n;i++){
        if(fabs(this->_enemies[i]->getX()-17)<1E-6&&fabs(this->_enemies[i]->getY()-8)<1E-6){
            vector<Enemy*>::iterator it;
            it=_enemies.begin()+i;
            delete(*it);
            it=this->_enemies.erase(it);
            continue;
        }
        this->_enemies[i]->paintEnemy(p);
    }
    delete p;
}
void MW2::paintGameworld(){
    this->_game.draw(pt);
}
void MW2::EnemyMove(){
    if(n<3&&flag==0){
    Enemy *e=new Enemy;
    this->_enemies.push_back(e);}
    else
        flag=1;
    n=this->_enemies.size();
    for(int i=0;i<n;i++)
        this->_enemies[i]->move();
    update();
}
