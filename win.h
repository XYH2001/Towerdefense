#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
//关卡一的胜利界面
namespace Ui {
class Win;
}

class Win : public QWidget
{
    Q_OBJECT

public:
    explicit Win(QWidget *parent = nullptr);
    ~Win();
    void paintEvent(QPaintEvent *);

signals:
    void showMW3();
    void exit();
    void toMW();
    void toMW2();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void receiveMW2();


private:
    Ui::Win *ui;
};

#endif // WIN_H
