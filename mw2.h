#ifndef MW2_H
#define MW2_H

#include <QMainWindow>
#include <QPushButton>
#include <QImage>
#include <QKeyEvent>
#include <QTimer>
#include "object.h"
#include "gameworld.h"
#include <QPainter>

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
    //void keyPressEvent(QKeyEvent *);

private:
    Ui::MW2 *ui;
    Gameworld _game;

signals:
    void showMainWindow();
    void exit();

private slots:
    void on_pushButton_clicked();
    void receiveMainWindow();
    void receiveexit();
};

#endif // MW2_H
