#include "win2.h"
#include "ui_win2.h"

Win2::Win2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win2)
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

Win2::~Win2()
{
    delete ui;
}
void Win2::on_pushButton_clicked(){
    this->hide();
    emit toMW3();
    emit toMW();
}
void Win2::receiveMW3(){
    this->show();
}
