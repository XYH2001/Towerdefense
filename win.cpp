#include "win.h"
#include "ui_win.h"
//关卡一的胜利界面
Win::Win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
    this->setFixedSize(600,450);
    ui->pushButton->setStyleSheet("QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton->move(100,300);
    ui->pushButton->resize(171,161);
    ui->pushButton_2->move(350,300);
    ui->pushButton_2->resize(171,161);
}

Win::~Win()
{
    delete ui;
}
void Win::on_pushButton_clicked(){
    this->hide();
    emit toMW2();
    emit toMW();
}
void Win::on_pushButton_2_clicked(){
    this->hide();
    emit showMW3();
}
void Win::receiveMW2(){
    this->show();
}
void Win::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":/pictures/win.jpg"));
}
