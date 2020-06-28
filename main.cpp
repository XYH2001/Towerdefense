#include "mainwindow.h"
#include "mw2.h"
#include "mw3.h"
#include "win.h"
#include "lose.h"
#include "win2.h"
#include "lose2.h"
#include <QPushButton>

#include <QApplication>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MW2 mw2;
    MW3 mw3;
    Win win;
    Lose lose;
    Win2 win2;
    Lose2 lose2;
    w.show();
    QObject::connect(&w,SIGNAL(showMW2()),&mw2,SLOT(receiveMainWindow()));
    QObject::connect(&w,SIGNAL(showMW3()),&mw3,SLOT(receiveMainWindow()));
    QObject::connect(&w,SIGNAL(exit()),&a,SLOT(quit()));
    QObject::connect(&w,SIGNAL(exit()),&mw2,SLOT(receiveexit()));
    QObject::connect(&w,SIGNAL(exit()),&mw3,SLOT(receiveexit()));
    QObject::connect(&mw2,SIGNAL(showMainWindow()),&w,SLOT(receiveMW2()));
    QObject::connect(&mw3,SIGNAL(showMainWindow()),&w,SLOT(receiveMW3()));
    QObject::connect(&mw2,SIGNAL(exit()),&a,SLOT(quit()));
    QObject::connect(&mw3,SIGNAL(exit()),&a,SLOT(quit()));
    QObject::connect(&win,SIGNAL(exit()),&a,SLOT(quit()));
    QObject::connect(&win,SIGNAL(showMW3()),&mw3,SLOT(receiveWin1()));
    QObject::connect(&win,SIGNAL(toMW()),&w,SLOT(receiveMW2()));
    QObject::connect(&win,SIGNAL(toMW2()),&mw2,SLOT(receiveWin()));
    QObject::connect(&mw2,SIGNAL(showWin()),&win,SLOT(receiveMW2()));
    QObject::connect(&win,SIGNAL(toMW2()),&mw2,SLOT(receiveWin()));
    QObject::connect(&lose,SIGNAL(toMW2()),&mw2,SLOT(receiveLose()));
    QObject::connect(&lose,SIGNAL(toMW()),&w,SLOT(receiveMW2()));
    QObject::connect(&mw2,SIGNAL(showLose()),&lose,SLOT(receiveMW2()));
    QObject::connect(&mw3,SIGNAL(showWin()),&win2,SLOT(receiveMW3()));
    QObject::connect(&mw3,SIGNAL(showLose()),&lose2,SLOT(receiveMW3()));
    QObject::connect(&win2,SIGNAL(toMW()),&w,SLOT(receiveMW3()));
    QObject::connect(&win2,SIGNAL(toMW3()),&mw3,SLOT(receiveWin2()));
    QObject::connect(&lose2,SIGNAL(toMW()),&w,SLOT(receiveMW3()));
    QObject::connect(&lose2,SIGNAL(toMW3()),&mw3,SLOT(receiveLose()));
    return a.exec();
}
