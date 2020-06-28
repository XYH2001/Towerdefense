#include "lose.h"
#include "ui_lose.h"

Lose::Lose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lose)
{
    ui->setupUi(this);   
    this->setFixedSize(600,450);
    ui->pushButton->setStyleSheet("QPushButton{font-family:'Impact';font-size:32px;}"
                                  "QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton->move(190,250);
    ui->pushButton->resize(171,161);
}

Lose::~Lose()
{
    delete ui;
}
void Lose::on_pushButton_clicked(){
    this->hide();
    emit toMW2();
    emit toMW();
}
void Lose::receiveMW2(){
    this->show();
}
