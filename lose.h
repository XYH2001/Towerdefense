#ifndef LOSE_H
#define LOSE_H

#include <QDialog>
//�ؿ�ʧ�ܺ����ʾ����
namespace Ui {
class Lose;
}

class Lose : public QDialog
{
    Q_OBJECT

public:
    explicit Lose(QWidget *parent = nullptr);
    ~Lose();

signals:
    void exit();
    void toMW();
    void toMW2();

private slots:
    void on_pushButton_clicked();
    void receiveMW2();

private:
    Ui::Lose *ui;
};

#endif // LOSE_H
