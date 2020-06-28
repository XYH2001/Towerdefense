#ifndef MW3_H
#define MW3_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTime>
#include <QTimer>
#include <QPainter>
#include <vector>
#include "shooter.h"
#include "enemy.h"
#include "object.h"
#include "gameworld2.h"
//关卡二界面
namespace Ui {
class MW3;
}

class MW3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW3(QWidget *parent = nullptr);
    ~MW3();
    void paintEvent(QPaintEvent *);
    void paintGameworld();
    int n=0;//三类敌人的个数
    int l=0;//三种射手的个数
    int flag=0;
    int n1=0,n2=0,n3=0;
    int shooteridx;
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *m);

private:
    Ui::MW3 *ui;
    Gameworld2 _game;
    vector<Enemy*> _enemies;
    vector<Shooter*> _shooters;
    QTimer *timer;
    QPixmap *pixmap;
    QPainter *pt;
    int gold=500;
    int carrotlife=10;

signals:
    void showMainWindow();
    void exit();
    void showLose();
    void showWin();

private slots:
    void on_pushButton_clicked();
    void receiveMainWindow();
    void receiveexit();
    void EnemyMove();
    void receiveWin1();
    void receiveWin2();
    void receiveLose();
};

#endif // MW3_H
