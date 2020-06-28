#ifndef MW2_H
#define MW2_H

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
#include "gameworld.h"
//�ؿ�һ����
namespace Ui {
class MW2;
}

class MW2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW2(QWidget *parent = nullptr);
    ~MW2();
    void paintEvent(QPaintEvent *);
    void paintGameworld();
    int n=0;//������˵��ܸ���
    int l=0;//�������ֵ��ܸ���
    int flag=0;
    int n1=0,n2=0,n3=0;
    int shooteridx;
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *m);

private:
    Ui::MW2 *ui;
    Gameworld _game;
    vector<Enemy*> _enemies;
    vector<Shooter*> _shooters;
    QTimer *timer;
    QPixmap *pixmap;
    QPainter *pt;
    int gold=600;//��Ϸ��ʼ�����
    int carrotlife=10;//�ܲ���ʼ����ֵ

signals:
    void showMainWindow();
    void exit();
    void showWin();
    void showLose();

private slots:
    void on_pushButton_clicked();
    void receiveMainWindow();
    void receiveexit();
    void EnemyMove();//�����ƶ�
    void receiveWin();
    void receiveLose();
};

#endif // MW2_H
