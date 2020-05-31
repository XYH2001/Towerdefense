#include "mw2.h"
#include "ui_mw2.h"
#include "mainwindow.h"
#include "icon.h"
#include <map>
#include <iostream>
using namespace std;

MW2::MW2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW2)
{
    ui->setupUi(this);
    setFixedSize(1200,744);
    ui->pushButton->setStyleSheet("QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton->move(1000,600);
    ui->pushButton->resize(171,161);

    _game.initGameworld("");
}

MW2::~MW2()
{
    delete ui;
}

void MW2::on_pushButton_clicked(){
    this->hide();
    emit showMainWindow();
}

void MW2::receiveMainWindow(){
    this->show();
}

void MW2::receiveexit(){
    emit exit();
}
void MW2::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/pictures/file4.png"));
}
