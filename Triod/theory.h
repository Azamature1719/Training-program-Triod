#ifndef THEORY_H
#define THEORY_H

#include <QWidget>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

namespace Ui {
class Theory;
}

class Theory : public QWidget
{
    Q_OBJECT

public:
    explicit Theory(QWidget *parent = nullptr);
    ~Theory();

signals:
    void back_toMenu();

private slots:
    void on_goMenu_clicked();

    void on_first_clicked();

    void on_third_clicked();

    void on_second_clicked();

private:
    int i = 0;
    QGraphicsPixmapItem *item;
    QGraphicsScene *scene;
    Ui::Theory *ui;
};

#endif // THEORY_H
