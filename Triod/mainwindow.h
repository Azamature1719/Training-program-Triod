#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_goMenu_clicked();
    void on_goTheory_clicked();
    void on_goDemo_clicked();
    void on_goTest_clicked();

    void on_goExam_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
