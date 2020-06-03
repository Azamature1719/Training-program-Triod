#ifndef THEORY_H
#define THEORY_H

#include <QWidget>

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

private:
    Ui::Theory *ui;
};

#endif // THEORY_H
