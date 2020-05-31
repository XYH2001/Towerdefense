#include "icon.h"
#include <iostream>
int ICON::GRID_SIZE=32;

ICON::ICON()
{

}
pair<string,ICON> pairArray[]=
{
    make_pair("shooter",ICON("shooter",5,3,1,1))
};
map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));
ICON::ICON(string name,int x,int y,int w,int h):typeName(name),X(x),Y(y),W(w),H(h){

}
ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv=ICON::GAME_ICON_SET.find(type);
    if(kv==ICON::GAME_ICON_SET.end()){
        cout<<"Error:cannot find ICON"<<endl;
    }
    else{
        return kv->second;
    }
}
