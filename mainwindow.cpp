#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mw2.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1200,744);
    ui->pushButton->setStyleSheet("QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton->move(400,430);
    ui->pushButton->resize(171,161);
    ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                  "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                  "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton_2->move(550,530);
    ui->pushButton_2->resize(171,161);
    ui->pushButton_3->setStyleSheet("QPushButton{font-family:'Impact';font-size:32px;}"
                                    "QPushButton{border-image:url(:pictures/file3.png);color:white;}"
                                    "QPushButton:hover{border-image:url(:/pictures/file3hover.png);color:white;}"
                                    "QPushButton:pressed{border-image:url(:/pictures/file3press.png);color:white;}");
    ui->pushButton_3->move(700,430);
    ui->pushButton_3->resize(171,161);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    this->hide();
    emit showMW2();
}

void MainWindow::on_pushButton_2_clicked(){
    emit exit();
}
void MainWindow::on_pushButton_3_clicked(){
    this->hide();
    emit showMW3();
}

void MainWindow::receiveMW2(){
    this->show();
}
void MainWindow::receiveMW3(){
    this->show();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/pictures/file2.jpg"));
}
