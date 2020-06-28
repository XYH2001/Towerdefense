#ifndef LOSE2_H
#define LOSE2_H

#include <QDialog>
#include <QPaintEvent>

namespace Ui {
class Lose2;
}

class Lose2 : public QDialog
{
    Q_OBJECT

public:
    explicit Lose2(QWidget *parent = nullptr);
    ~Lose2();

signals:
    void toMW();
    void toMW3();
    void exit();

private slots:
    void on_pushButton_clicked();
    void receiveMW3();

private:
    Ui::Lose2 *ui;
};

#endif // LOSE2_H
