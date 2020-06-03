#ifndef PRAKTIKUM_H
#define PRAKTIKUM_H

#include <QWidget>

namespace Ui {
class Demonstration;
}

class Demonstration : public QWidget
{
    Q_OBJECT

public:
    explicit Demonstration(QWidget *parent = nullptr);
    ~Demonstration();

signals:
    void back_toMenu();

private slots:
    void on_goMenu_clicked();

private:
    Ui::Demonstration *ui;
};

#endif // PRAKTIKUM_H
