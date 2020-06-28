#include "gameworld2.h"

Gameworld2::Gameworld2()
{

}
void Gameworld2::initGameworld(string mapFile){
    Object **p1=new Object*[2];
    for(int i=0;i<2;i++){
        p1[i]=new Object;
        p1[i]->initObj("ice1");
        p1[i]->setX(5*i);
        p1[i]->setY(3);
        this->_objects.push_back(p1[i]);
    }

    Object *p2=new Object;
    p2->initObj("ice3");
    p2->setX(10);
    p2->setY(3);
    this->_objects.push_back(p2);

    Object *p3=new Object;
    p3->initObj("ice2");
    p3->setX(7);
    p3->setY(5);
    this->_objects.push_back(p3);

    Object *p4=new Object;
    p4->initObj("ice4");
    p4->setX(11);
    p4->setY(5);
    this->_objects.push_back(p4);

    Object *p5=new Object;
    p5->initObj("ice3");
    p5->setX(7);
    p5->setY(6);
    this->_objects.push_back(p5);

    Object *p6=new Object;
    p6->initObj("ice1");
    p6->setX(8);
    p6->setY(8);
    this->_objects.push_back(p6);

    Object *p7=new Object;
    p7->initObj("ice3");
    p7->setX(13);
    p7->setY(6);
    this->_objects.push_back(p7);

    Object *p8=new Object;
    p8->initObj("ice2");
    p8->setX(14);
    p8->setY(6);
    this->_objects.push_back(p8);

    Object *p9=new Object;
    p9->initObj("sign");
    p9->setX(1);
    p9->setY(1);
    this->_objects.push_back(p9);

    Object *p10=new Object;
    p10->initObj("carrot");
    p10->setX(15.5);
    p10->setY(4.5);
    this->_objects.push_back(p10);

    Object *p11=new Object;
    p11->initObj("carrotlife");
    p11->setX(17.5);
    p11->setY(5);
    this->_objects.push_back(p11);

    Object *p12=new Object;
    p12->initObj("column");
    p12->setX(3);
    p12->setY(0);
    this->_objects.push_back(p12);

    Object *p13=new Object;
    p13->initObj("coin");
    p13->setX(4);
    p13->setY(0);
    this->_objects.push_back(p13);

    Object **p14=new Object*[2];
    for(int i=0;i<2;i++){
        p14[i]=new Object;
        p14[i]->initObj("coral");
    }
    p14[0]->setX(13);
    p14[0]->setY(2);
    p14[1]->setX(5);
    p14[1]->setY(8);
    this->_objects.push_back(p14[0]);
    this->_objects.push_back(p14[1]);

    Object **p15=new Object*[2];
    for(int i=0;i<2;i++){
        p15[i]=new Object;
        p15[i]->initObj("seaweed1");
    }
    p15[0]->setX(0);
    p15[0]->setY(4);
    p15[1]->setX(15);
    p15[1]->setY(8);
    this->_objects.push_back(p15[0]);
    this->_objects.push_back(p15[1]);

    Object **p17=new Object*[7];
    for(int i=0;i<7;i++){
        p17[i]=new Object;
        p17[i]->initObj("seaweed2");
    }
    for(int i=0;i<3;i++){
        p17[i]->setX(5+i);
        p17[i]->setY(4);
        this->_objects.push_back(p17[i]);
    }
    for(int i=3;i<5;i++){
        p17[i]->setX(6+i);
        p17[i]->setY(2);
        this->_objects.push_back(p17[i]);
    }
    p17[5]->setX(9);
    p17[5]->setY(6);
    p17[6]->setX(9);
    p17[6]->setY(9);
    this->_objects.push_back(p17[5]);
    this->_objects.push_back(p17[6]);

    Object **p18=new Object*[3];
    for(int i=0;i<3;i++){
        p18[i]=new Object;
        p18[i]->initObj("starfish");
    }
    p18[0]->setX(9);
    p18[0]->setY(4);
    p18[1]->setX(14);
    p18[1]->setY(7);
    p18[2]->setX(13);
    p18[2]->setY(9);
    for(int i=0;i<3;i++){
        this->_objects.push_back(p18[i]);
    }
}
void Gameworld2::draw(QPainter *painter){
    int n=this->_objects.size();
    for(int i=0;i<n;i++){
        this->_pix=QPixmap::fromImage(this->_objects[i]->getImage());
        painter->drawPixmap(this->_objects[i]->getX()*64,this->_objects[i]->getY()*64,this->_pix);
    }
}
bool Gameworld2::hasObject(double x, double y){
    vector<Object*>::iterator it;
    it=_objects.begin();
    while(it!=_objects.end()){
        if(fabs((*it)->getX()-x)<1E-6&&fabs((*it)->getY()-y)<1E-6)
            return true;
        else if(x>(*it)->getX()&&x<((*it)->getX()+(*it)->getW())&&y>(*it)->getY()&&y<((*it)->getY()+(*it)->getH()))
            return true;
        else
            it++;
    }
    return false;
}
