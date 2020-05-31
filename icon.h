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
    ICON(string name,int x,int y,int w,int h);
    string getTypeName() const{return this->typeName;}
    int getX() const{return this->X;}
    int getY() const{return this->Y;}
    int getW() const{return this->W;}
    int getH() const{return this->H;}
private:
    string typeName;
    int X,Y,W,H;
};

#endif // ICON_H
