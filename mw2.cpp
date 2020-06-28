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

double dist(double x1,double y1,double x2,double y2){
    double d;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    d=sqrt(d);
    return d;
}

void MW2::on_pushButton_clicked(){
    this->hide();
    emit showMainWindow();
}

void MW2::receiveMainWindow(){
    this->show();
    QMediaPlayer *player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/bgm.mp3"));
    player->setVolume(25);
    player->play();
    timer->start(100);
}

void MW2::receiveexit(){
    emit exit();
}
void MW2::receiveWin(){
    this->hide();
}
void MW2::receiveLose(){
    this->hide();
}
void MW2::paintEvent(QPaintEvent *){
    QPainter *p=new QPainter(this);
    p->drawPixmap(0,0,this->width(),this->height(),*pixmap);
    for(int i=0;i<n;i++){
        this->_enemies[i]->paintEnemy(p);
    }
    for(int i=0;i<l;i++){
        this->_shooters[i]->paintShooter(p);
        if(_shooters[i]->ifhasShoot())//如果有子弹则绘制，没有则不绘制
            _shooters[i]->paintBullet(p);
    }
    p->setPen(Qt::black);//画出金币数和萝卜生命值
    QFont font1("Calibri",15,35,false);
    QFont font2("Calibri",10,45,false);
    p->setFont(font1);
    p->drawText(5.4*64,0.75*64,QString("%1").arg(this->gold));
    p->setFont(font2);
    p->drawText(16.5*64,7*64,QString("%1").arg(this->carrotlife));

    delete p;
}
void MW2::paintGameworld(){
    this->_game.draw(pt);
}
void MW2::EnemyMove(){
    flag++;
    n=this->_enemies.size();
    if(n1<8&&flag==10){//控制第一种敌人的个数和生成时间间隔
        Enemy *e=new Enemy(1,1);
        this->_enemies.push_back(e);
        flag=0;
        n1++;
    }
    if(flag==210 && n2<10){//控制第二种敌人的个数和生成时间间隔
        Enemy *e=new Enemy(2,1);
        this->_enemies.push_back(e);
        flag=200;
        n2++;
    }
    if(flag==360 && n3<12){//控制第三种敌人的个数和生成时间间隔
        Enemy *e=new Enemy(3,1);
        this->_enemies.push_back(e);
        flag=350;
        n3++;
    }
    n=this->_enemies.size();
    for(int i=0;i<n;i++){
        if(fabs(this->_enemies[i]->getX()-17)<1E-6&&fabs(this->_enemies[i]->getY()-7.5)<1E-6){
            //如果到达萝卜处则删除该敌人同时萝卜生命值减少
            QMediaPlayer *player=new QMediaPlayer;
            player->setMedia(QUrl("qrc:/music/eat.mp3"));
            player->setVolume(60);
            player->play();
            this->carrotlife--;
            if(this->carrotlife<=0){
                emit showLose();
                timer->stop();
            }
            vector<Enemy*>::iterator it;
            it=_enemies.begin()+i;
            delete(*it);
            it=this->_enemies.erase(it);
            continue;
        }
        this->_enemies[i]->move(1);
    }
    n=this->_enemies.size();
    if(n>0){
        vector<Enemy*>::iterator e;
        e=_enemies.begin();
        for(int i=0;i<l;i++){//每个炮塔都遍历游戏中所有敌人
            _shooters[i]->flag++;
            if(!_shooters[i]->ifhasShoot() && _shooters[i]->flag==4){//flag为控制产生子弹的速率
                n=this->_enemies.size();
                _shooters[i]->flag=0;
                if(n>0){
                    _shooters[i]->target=0;
                    e=_enemies.begin();
                    while(e!=_enemies.end()){//没有子弹且有敌人进入攻击范围时初始化一个子弹
                        if(dist(_shooters[i]->getX()+0.5,_shooters[i]->getY()+0.5,(*e)->getX()+0.5,(*e)->getY()+0.5)<_shooters[i]->getRadius()){
                            if(_shooters[i]->getType()=="shooter10"||_shooters[i]->getType()=="shooter11")
                                _shooters[i]->initBullet((*e)->getX()+0.5,(*e)->getY()+0.5,1);
                            else if(_shooters[i]->getType()=="shooter20"||_shooters[i]->getType()=="shooter21")
                                _shooters[i]->initBullet((*e)->getX()+0.5,(*e)->getY()+0.5,2);
                            else if(_shooters[i]->getType()=="shooter30"||_shooters[i]->getType()=="shooter31")
                                _shooters[i]->initBullet((*e)->getX()+0.5,(*e)->getY()+0.5,3);
                            break;
                        }
                        else{
                            e++;
                            _shooters[i]->target++;//target为目标敌人下标
                        }
                    }
                }
            }
            if(_shooters[i]->ifhasShoot() && _shooters[i]->ifgetTarget()){//如果此时有子弹且子弹到达目标点，则敌人生命值对应减少且删除该子弹
                    e=_enemies.begin();
                    (*(e+_shooters[i]->target))->setlife(_shooters[i]->getMinus());
                    _shooters[i]->deleteBullet();
                    _shooters[i]->flag=0;
                    if((*(e+_shooters[i]->target))->getCurrentLife()<=0){//敌人生命值减为0时删除同时增加金币数
                        this->gold += (*(e+_shooters[i]->target))->getBonus();
                        delete (*(e+_shooters[i]->target));
                        e=_enemies.erase((e+_shooters[i]->target));
                    }
                    _shooters[i]->target=0;
             }
            else if(_shooters[i]->ifhasShoot() &&
           dist(_shooters[i]->getX()+0.5,_shooters[i]->getY()+0.5,_shooters[i]->getBulletX()+0.5,_shooters[i]->getBulletY()+0.5)>_shooters[i]->getRadius()){
                //由于double类型的精度问题可能会有某些子弹未到达指定目标，此时如果子弹与炮塔距离超过炮塔攻击范围，同样也删除子弹
                _shooters[i]->deleteBullet();
                _shooters[i]->flag=0;//把产生子弹的速率控制变量和目标敌人下标变量重置为0
                _shooters[i]->target=0;
            }
            if(_shooters[i]->ifhasShoot())//若有子弹则子弹移动
                _shooters[i]->BulletMove();
        }
    }
    n=this->_enemies.size();
    if(n==0){//当场上敌人数为0时将所有炮塔的子弹清除
        for(int i=0;i<l;i++){
            if(_shooters[i]->ifhasShoot())
                _shooters[i]->deleteBullet();
        }
    }
    n=this->_enemies.size();
    if(n==0 && this->carrotlife>0 && n3==12){//此时游戏胜利
        emit showWin();
        timer->stop();
    }
    update();
}
void MW2::keyPressEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_1)
        shooteridx=1;//shooteridx为炮塔标识
    else if(e->key()==Qt::Key_2)
        shooteridx=2;
    else if(e->key()==Qt::Key_3)
        shooteridx=3;
    else if(e->key()==Qt::Key_L)
        shooteridx=11;
    else if(e->key()==Qt::Key_R)
        shooteridx=-1;
}
void MW2::mousePressEvent(QMouseEvent *e){
    int ex=e->x()/64;
    int ey=e->y()/64;
    double x=ex;
    double y=ey;
    vector<Shooter*>::iterator it;
    string name="none";//得到当前坐标下的物体种类，是无还是有某种炮塔，以便后面对应升级炮塔
    if(l>0){
        it=_shooters.begin();
        while(it!=_shooters.end()){
            if(fabs((*it)->getX()-x)<1E-6 && fabs((*it)->getY()-y)<1E-6){
                name=(*it)->getType();
                break;
            }
            else
                it++;
        }
    }
    if(shooteridx==1 && name=="none" && !this->_game.hasObject(e->x()/64.0,e->y()/64.0) && this->gold>=200){//炮塔一种植
        Shooter *shooter10=new Shooter(x,y,10);
        this->gold -= shooter10->getPrice();
        this->_shooters.push_back(shooter10);
        shooteridx=0;
    }
    if(shooteridx==2 && name=="none" && !this->_game.hasObject(e->x()/64.0,e->y()/64.0) && this->gold>=300){//炮塔二种植
        Shooter *shooter20=new Shooter(x,y,20);
        this->gold -= shooter20->getPrice();
        this->_shooters.push_back(shooter20);
        shooteridx=0;
    }
    if(shooteridx==3 && name=="none" && !this->_game.hasObject(e->x()/64.0,e->y()/64.0) && this->gold>=450){//炮塔三种植
        Shooter *shooter30=new Shooter(x,y,30);
        this->gold -= shooter30->getPrice();
        this->_shooters.push_back(shooter30);
        shooteridx=0;
    }
    if(shooteridx==11 && name=="shooter10" && this->gold>=300){//炮塔一升级
        delete (*it);//删除原对象
        it=this->_shooters.erase(it);
        Shooter *shooter11=new Shooter(x,y,11);
        this->gold -= shooter11->getPrice();
        this->_shooters.push_back(shooter11);
        shooteridx=0;
    }
    if(shooteridx==11 && name=="shooter20" && this->gold>=420){//炮塔二升级
        delete (*it);
        it=this->_shooters.erase(it);
        Shooter *shooter21=new Shooter(x,y,21);
        this->gold -= shooter21->getPrice();
        this->_shooters.push_back(shooter21);
        shooteridx=0;
    }
    if(shooteridx==11 && name=="shooter30" && this->gold>=550){//炮塔三升级
        delete (*it);
        it=this->_shooters.erase(it);
        Shooter *shooter31=new Shooter(x,y,31);
        this->gold -= shooter31->getPrice();
        this->_shooters.push_back(shooter31);
        shooteridx=0;
    }
    if(shooteridx==-1 && name!="none"){//炮塔一拆除
        this->gold += (*it)->getBonus();
        delete (*it);
        it=this->_shooters.erase(it);
        shooteridx=0;
    }
    if(shooteridx==-1 && name!="none"){//炮塔二拆除
        this->gold += (*it)->getBonus();
        delete (*it);
        it=this->_shooters.erase(it);
        shooteridx=0;
    }
    if(shooteridx==-1 && name!="none"){//炮塔三拆除
        this->gold += (*it)->getBonus();
        delete (*it);
        it=this->_shooters.erase(it);
        shooteridx=0;
    }
    l=_shooters.size();
    update();
}

