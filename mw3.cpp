#include "mw3.h"
#include "ui_mw3.h"
//以下的函数和MW2中类似
MW3::MW3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW3)
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

    pixmap=new QPixmap(":/pictures/background2.png");
    pt=new QPainter(pixmap);
    _game.initGameworld("");
    paintGameworld();
}

MW3::~MW3()
{
    pt->end();
    delete ui;
    delete pixmap;
    delete timer;
    delete pt;
}

double d(double x1,double y1,double x2,double y2){
    double d;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    d=sqrt(d);
    return d;
}

void MW3::receiveMainWindow(){
    this->show();
    QMediaPlayer *player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/bgm.mp3"));
    player->setVolume(25);
    player->play();
    timer->start(100);
}
void MW3::receiveexit(){
    emit exit();
}
void MW3::receiveLose(){
    this->hide();
}
void MW3::on_pushButton_clicked(){
    this->hide();
    emit showMainWindow();
}
void MW3::paintEvent(QPaintEvent *){
    QPainter *p=new QPainter(this);
    p->drawPixmap(0,0,this->width(),this->height(),*pixmap);
    for(int i=0;i<n;i++){
        this->_enemies[i]->paintEnemy(p);
    }
    for(int i=0;i<l;i++){
        this->_shooters[i]->paintShooter(p);
        if(_shooters[i]->ifhasShoot())
            _shooters[i]->paintBullet(p);
    }
    p->setPen(Qt::black);
    QFont font1("Calibri",15,35,false);
    QFont font2("Calibri",10,45,false);
    p->setFont(font1);
    p->drawText(5.4*64,0.75*64,QString("%1").arg(this->gold));
    p->setFont(font2);
    p->drawText(18*64,5.4*64,QString("%1").arg(this->carrotlife));

    delete p;
}
void MW3::paintGameworld(){
    this->_game.draw(pt);
}
void MW3::EnemyMove(){
    flag++;
    n=this->_enemies.size();
    if(n1<10&&flag==10){
        Enemy *e=new Enemy(1,1);
        this->_enemies.push_back(e);
        flag=0;
        n1++;
    }
    if(flag==210 && n2<15){
        Enemy *e=new Enemy(2,1);
        this->_enemies.push_back(e);
        flag=200;
        n2++;
    }
    if(flag==360 && n3<20){
        Enemy *e=new Enemy(3,1);
        this->_enemies.push_back(e);
        flag=350;
        n3++;
    }
    n=this->_enemies.size();
    for(int i=0;i<n;i++){
        if(fabs(this->_enemies[i]->getX()-15.5)<1E-6&&fabs(this->_enemies[i]->getY()-5.5)<1E-6){
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
        this->_enemies[i]->move(2);
    }
    n=this->_enemies.size();
    if(n>0){
        vector<Enemy*>::iterator e;
        e=_enemies.begin();
        for(int i=0;i<l;i++){
            _shooters[i]->flag++;
            if(!_shooters[i]->ifhasShoot() && _shooters[i]->flag==6){
                n=this->_enemies.size();
                _shooters[i]->flag=0;
                if(n>0){
                    _shooters[i]->target=0;
                    e=_enemies.begin();
                    while(e!=_enemies.end()){
                        if(d(_shooters[i]->getX()+0.5,_shooters[i]->getY()+0.5,(*e)->getX()+0.5,(*e)->getY()+0.5)<_shooters[i]->getRadius()){
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
                            _shooters[i]->target++;
                        }
                    }
                }
            }
            if(_shooters[i]->ifhasShoot() && _shooters[i]->ifgetTarget()){
                    e=_enemies.begin();
                    (*(e+_shooters[i]->target))->setlife(_shooters[i]->getMinus());
                    _shooters[i]->deleteBullet();
                    _shooters[i]->flag=0;
                    if((*(e+_shooters[i]->target))->getCurrentLife()<=0){
                        this->gold += (*(e+_shooters[i]->target))->getBonus();
                        delete (*(e+_shooters[i]->target));
                        e=_enemies.erase((e+_shooters[i]->target));
                    }
                    _shooters[i]->target=0;
             }
            else if(_shooters[i]->ifhasShoot() && d(_shooters[i]->getX()+0.5,_shooters[i]->getY()+0.5,_shooters[i]->getBulletX()+0.5,_shooters[i]->getBulletY()+0.5)>_shooters[i]->getRadius()){
                _shooters[i]->deleteBullet();
                _shooters[i]->flag=0;
                _shooters[i]->target=0;
            }
            if(_shooters[i]->ifhasShoot())
                _shooters[i]->BulletMove();
        }
    }
    n=this->_enemies.size();
    if(n==0){
        for(int i=0;i<l;i++){
            if(_shooters[i]->ifhasShoot())
                _shooters[i]->deleteBullet();
        }
    }
    n=this->_enemies.size();
    if(n==0 && this->carrotlife>0 && n3==20){
        emit showWin();
        timer->stop();
    }
    update();
}
void MW3::keyPressEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_1)
        shooteridx=1;
    else if(e->key()==Qt::Key_2)
        shooteridx=2;
    else if(e->key()==Qt::Key_3)
        shooteridx=3;
    else if(e->key()==Qt::Key_L)
        shooteridx=11;
    else if(e->key()==Qt::Key_R)
        shooteridx=-1;
}
void MW3::mousePressEvent(QMouseEvent *e){
    int ex=e->x()/64;
    int ey=e->y()/64;
    double x=ex;
    double y=ey;
    vector<Shooter*>::iterator it;
    string name="none";
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
    if(shooteridx==1 && name=="none" && !this->_game.hasObject(e->x()/64.0,e->y()/64.0) && this->gold>=200){
        Shooter *shooter10=new Shooter(x,y,10);
        this->gold -= shooter10->getPrice();
        this->_shooters.push_back(shooter10);
        shooteridx=0;
    }
    if(shooteridx==2 && name=="none" && !this->_game.hasObject(e->x()/64.0,e->y()/64.0) && this->gold>=300){
        Shooter *shooter20=new Shooter(x,y,20);
        this->gold -= shooter20->getPrice();
        this->_shooters.push_back(shooter20);
        shooteridx=0;
    }
    if(shooteridx==3 && name=="none" && !this->_game.hasObject(e->x()/64.0,e->y()/64.0) && this->gold>=450){
        Shooter *shooter30=new Shooter(x,y,30);
        this->gold -= shooter30->getPrice();
        this->_shooters.push_back(shooter30);
        shooteridx=0;
    }
    if(shooteridx==11 && name=="shooter10" && this->gold>=300){
        delete (*it);
        it=this->_shooters.erase(it);
        Shooter *shooter11=new Shooter(x,y,11);
        this->gold -= shooter11->getPrice();
        this->_shooters.push_back(shooter11);
        shooteridx=0;
    }
    if(shooteridx==11 && name=="shooter20" && this->gold>=420){
        delete (*it);
        it=this->_shooters.erase(it);
        Shooter *shooter21=new Shooter(x,y,21);
        this->gold -= shooter21->getPrice();
        this->_shooters.push_back(shooter21);
        shooteridx=0;
    }
    if(shooteridx==11 && name=="shooter30" && this->gold>=550){
        delete (*it);
        it=this->_shooters.erase(it);
        Shooter *shooter31=new Shooter(x,y,31);
        this->gold -= shooter31->getPrice();
        this->_shooters.push_back(shooter31);
        shooteridx=0;
    }
    if(shooteridx==-1 && name!="none"){
        this->gold += (*it)->getBonus();
        delete (*it);
        it=this->_shooters.erase(it);
        shooteridx=0;
    }
    if(shooteridx==-1 && name!="none"){
        this->gold += (*it)->getBonus();
        delete (*it);
        it=this->_shooters.erase(it);
        shooteridx=0;
    }
    if(shooteridx==-1 && name!="none"){
        this->gold += (*it)->getBonus();
        delete (*it);
        it=this->_shooters.erase(it);
        shooteridx=0;
    }
    l=_shooters.size();
    update();
}
void MW3::receiveWin1(){
    this->show();
    QMediaPlayer *player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music/bgm.mp3"));
    player->setVolume(25);
    player->play();
    timer->start(100);
}
void MW3::receiveWin2(){
    this->hide();
}
