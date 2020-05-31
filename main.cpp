#include "mainwindow.h"
#include "mw2.h"
#include <QPushButton>

#include <QApplication>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MW2 mw2;
    w.show();
    QObject::connect(&w,SIGNAL(showMW2()),&mw2,SLOT(receiveMainWindow()));
    QObject::connect(&mw2,SIGNAL(showMainWindow()),&w,SLOT(receiveMW2()));
    QObject::connect(&w,SIGNAL(exit()),&a,SLOT(quit()));
    QObject::connect(&mw2,SIGNAL(exit()),&a,SLOT(quit()));
    QObject::connect(&w,SIGNAL(exit()),&mw2,SLOT(receiveexit()));
    return a.exec();
}
