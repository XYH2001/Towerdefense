#include "icon.h"
#include <iostream>
int ICON::GRID_SIZE=64;

ICON::ICON()
{

}
pair<string,ICON> pairArray[]=
{
    make_pair("road1",ICON("road1",0,3,3,1)),
    make_pair("road2",ICON("road2",4,0,1,3)),
    make_pair("beach",ICON("beach",5,0,4,4)),
    make_pair("column",ICON("column",0,8,12,1)),
    make_pair("house",ICON("house",2,5,2,3)),
    make_pair("tree",ICON("tree",0,0,2,2)),
    make_pair("coin",ICON("coin",15,2,1,1)),
    make_pair("shell1",ICON("shell1",9,0,1,1)),
    make_pair("shell2",ICON("shell2",10,0,1,1)),
    make_pair("shell3",ICON("shell3",11,2,1,1)),
    make_pair("sign",ICON("sign",5,5,1.5,2)),
    make_pair("carrot",ICON("carrot",12.5,2,1.5,2)),
};
map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));
ICON::ICON(string name,double x,double y,double w,double h):typeName(name),X(x),Y(y),W(w),H(h){

}
ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv=ICON::GAME_ICON_SET.find(type);
    if(kv==ICON::GAME_ICON_SET.end()){
        cout<<"Error:cannot find ICON"<<endl;
        return ICON();
    }
    else{
        return kv->second;
    }
}
