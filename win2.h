#ifndef WIN2_H
#define WIN2_H

#include <QDialog>
#include <QPaintEvent>
//关卡二的胜利界面
namespace Ui {
class Win2;
}

class Win2 : public QDialog
{
    Q_OBJECT

public:
    explicit Win2(QWidget *parent = nullptr);
    ~Win2();

signals:
    void toMW();
    void toMW3();
    void exit();

private slots:
    void on_pushButton_clicked();
    void receiveMW3();

private:
    Ui::Win2 *ui;
};

#endif // WIN2_H
