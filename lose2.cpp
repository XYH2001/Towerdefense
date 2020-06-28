#include "lose2.h"
#include "ui_lose2.h"

Lose2::Lose2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lose2)
{
    ui->setupUi(this);
    this->setFixedSize(600,450);
    ui->pushButton->setStyleSheet("QPushButton{font-family:'Impact';font-size:32px;}"
                                  "QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton->move(190,250);
    ui->pushButton->resize(171,161);//设置按钮样式表
}

Lose2::~Lose2()
{
    delete ui;
}
void Lose2::on_pushButton_clicked(){
    this->hide();
    emit toMW();
    emit toMW3();
}
void Lose2::receiveMW3(){
    this->show();
}
