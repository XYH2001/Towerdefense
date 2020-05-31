#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "object.h"
#include "icon.h"
#include <vector>
#include <string>
#include <QPainter>


class Gameworld
{
public:
    Gameworld();
    void initGameworld(string mapFile);
    void show(QPainter *painter);
    void eraseObj(int x,int y);
private:
    vector<Object *> _objects;
};

#endif // GAMEWORLD_H
