#ifndef MW2_H
#define MW2_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include "object.h"
#include "gameworld.h"
#include <QPainter>
#include "enemy.h"
#include <vector>

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
    int n=0;
    int flag=0;

/*protected slots:
    void handleEnemyMove();*/

private:
    Ui::MW2 *ui;
    Gameworld _game;
    vector<Enemy*> _enemies;
    QTimer *timer;
    QPixmap *pixmap;
    QPainter *pt;

signals:
    void showMainWindow();
    void exit();

private slots:
    void on_pushButton_clicked();
    void receiveMainWindow();
    void receiveexit();
    //void paintEnemy1();
    void EnemyMove();
};

#endif // MW2_H
