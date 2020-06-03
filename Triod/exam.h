#ifndef EXAM_H
#define EXAM_H

#include <QWidget>

namespace Ui {
class Exam;
}

class Exam : public QWidget
{
    Q_OBJECT

public:
    explicit Exam(QWidget *parent = nullptr);
    ~Exam();

signals:
    void back_toMenu();

private slots:
    void on_goMenu_clicked();

private:
    Ui::Exam *ui;
};

#endif // EXAM_H
