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
    //ȷ�������������ز�ͼƬ��λ�ã��ߡ��������
    static ICON findICON(string type);
    //���������������ҵ�ͼ��
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
