#ifndef ICON_H
#define ICON_H
#include <string>
#include <map>
using namespace std;

class ICON
{
public:
    ICON();
    static int GRID_SIZE;
    static map<string,ICON> GAME_ICON_SET;
    //确定各类物体子素材图片的位置，高、宽等数据
    static ICON findICON(string type);
    //根据物体类型名找到图标
    ICON(string name,double x,double y,double w,double h);
    string getTypeName() const{return this->typeName;}
    double getX() const{return this->X;}
    double getY() const{return this->Y;}
    double getW() const{return this->W;}
    double getH() const{return this->H;}
private:
    string typeName;
    double X,Y,W,H;
};

#endif // ICON_H
