#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clickablelabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->theoryPage, SIGNAL(back_toMenu()), this, SLOT(on_goMenu_clicked()));
    connect(ui->demoPage, SIGNAL(back_toMenu()), this, SLOT(on_goMenu_clicked()));
    connect(ui->examPage, SIGNAL(back_toMenu()), this, SLOT(on_goMenu_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_goMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void MainWindow::on_goTheory_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->theoryPage);
}

void MainWindow::on_goDemo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->demoPage);
}

void MainWindow::on_goExam_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->examPage);
}

void MainWindow::on_goTheory_linkHovered(const QString &link)
{
    ui->goTheory->setStyleSheet("QLabel { background-color : lightgrey; }");
}
