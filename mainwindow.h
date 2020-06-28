#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QPoint>
#include "mw2.h"
#include <QPainter>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void showMW2();
    void exit();
    void showMW3();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *);

private slots:
    void receiveMW2();
    void receiveMW3();
    void on_pushButton_clicked();//显示关卡1
    void on_pushButton_2_clicked();//退出界面
    void on_pushButton_3_clicked();//显示关卡2
};
#endif // MAINWINDOW_H
