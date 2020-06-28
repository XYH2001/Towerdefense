#include "gameworld.h"
#include "object.h"
#include "icon.h"

Gameworld::Gameworld()
{

}
void Gameworld::initGameworld(string mapFile){
    Object **p1=new Object* [3];//指针数组
    for(int i=0;i<3;i++){
        p1[i]=new Object;//每一个指针还要初始化
        p1[i]->initObj("road1");
        p1[i]->setX(3*i);
        p1[i]->setY(3);
        this->_objects.push_back(p1[i]);
    }

    Object **p2=new Object*[2];
    for(int i=0;i<2;i++){
        p2[i]=new Object();
        p2[i]->initObj("road2");
        p2[i]->setX(9);
        p2[i]->setY(3+3*i);
        this->_objects.push_back(p2[i]);
    }

    Object **p3=new Object* [3];
    for(int i=0;i<3;i++){
        p3[i]=new Object;
        p3[i]->initObj("road1");
        p3[i]->setX(10+3*i);
        p3[i]->setY(8);
        this->_objects.push_back(p3[i]);
    }

    Object *p4=new Object;
    p4->initObj("column");
    p4->setX(3);
    p4->setY(0);
    this->_objects.push_back(p4);

    Object *p5=new Object;
    p5->initObj("house");
    p5->setX(12);
    p5->setY(3);
    this->_objects.push_back(p5);

    Object **p6=new Object*[3];
    for(int i=0;i<3;i++){
        p6[i]=new Object;
        p6[i]->initObj("tree");
        p6[i]->setX(10+2*i);
        p6[i]->setY(1);
        this->_objects.push_back(p6[i]);
    }
    for(int i=0;i<2;i++){
        p6[i]=new Object;
        p6[i]->initObj("tree");
        p6[i]->setX(14);
        p6[i]->setY(3+2*i);
        this->_objects.push_back(p6[i]);
    }

    Object *p7=new Object;
    p7->initObj("house");
    p7->setX(5);
    p7->setY(5);
    this->_objects.push_back(p7);

    Object **p8=new Object*[5];
    for(int i=0;i<3;i++){
        p8[i]=new Object;
        p8[i]->initObj("tree");
        p8[i]->setX(3);
        p8[i]->setY(4+2*i);
        this->_objects.push_back(p8[i]);
    }
    for(int i=0;i<2;i++){
        p8[i]=new Object;
        p8[i]->initObj("tree");
        p8[i]->setX(5+2*i);
        p8[i]->setY(8);
        this->_objects.push_back(p8[i]);
    }

    Object *p9=new Object;
    p9->initObj("coin");
    p9->setX(4);
    p9->setY(0);
    this->_objects.push_back(p9);

    Object **p10=new Object*[3];
    for(int i=0;i<3;i++){
        p10[i]=new Object;
        p10[i]->initObj("shell1");
    }
    p10[0]->setX(5);
    p10[0]->setY(2);
    p10[1]->setX(11);
    p10[1]->setY(9);
    p10[2]->setX(13);
    p10[2]->setY(7);
    for(int i=0;i<3;i++){
        this->_objects.push_back(p10[i]);
    }

    Object **p11=new Object*[3];
    for(int i=0;i<3;i++){
        p11[i]=new Object;
        p11[i]->initObj("shell2");
    }
    p11[0]->setX(9);
    p11[0]->setY(1);
    p11[1]->setX(2);
    p11[1]->setY(6);
    p11[2]->setX(0);
    p11[2]->setY(4);
    for(int i=0;i<3;i++){
        this->_objects.push_back(p11[i]);
    }

    Object **p12=new Object*[2];
    for(int i=0;i<2;i++){
        p12[i]=new Object;
        p12[i]->initObj("shell3");
    }
    p12[0]->setX(8);
    p12[0]->setY(7);
    p12[1]->setX(17);
    p12[1]->setY(5);
    this->_objects.push_back(p12[0]);
    this->_objects.push_back(p12[1]);

    Object *p13=new Object;
    p13->initObj("sign");
    p13->setX(1);
    p13->setY(1);
    this->_objects.push_back(p13);

    Object *p14=new Object;
    p14->initObj("carrot");
    p14->setX(17);
    p14->setY(6.5);
    this->_objects.push_back(p14);

    Object *p15=new Object;
    p15->initObj("carrotlife");
    p15->setX(16);
    p15->setY(6.6);
    this->_objects.push_back(p15);

}
void Gameworld::draw(QPainter *painter){
    int n=this->_objects.size();
    for(int i=0;i<n;i++){
        this->_pix=QPixmap::fromImage(this->_objects[i]->getImage());
        painter->drawPixmap(this->_objects[i]->getX()*64,this->_objects[i]->getY()*64,this->_pix);
    }  
}
bool Gameworld::hasObject(double x, double y){
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
