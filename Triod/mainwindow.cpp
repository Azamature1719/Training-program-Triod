#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clickablelabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMinimumSize(QSize(1238, 950));
    this->setMaximumSize(QSize(1238, 750));


    timer = new QTimer;
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
    ui->goTheory->startTransitTitles();
    timer->singleShot(200, this, SLOT(TheoryGo()));
}

void MainWindow::on_goDemo_clicked()
{
    ui->goDemo->startTransitTitles();
    timer->singleShot(200, this, SLOT(DemoGo()));
}

void MainWindow::on_goExam_clicked()
{
    ui->goExam->startTransitTitles();
    timer->singleShot(200, this, SLOT(ExamGo()));
}

void MainWindow::ExamGo()
{
    ui->stackedWidget->setCurrentWidget(ui->examPage);
}

void MainWindow::TheoryGo()
{
    ui->stackedWidget->setCurrentWidget(ui->theoryPage);
}

void MainWindow::DemoGo()
{
    ui->stackedWidget->setCurrentWidget(ui->demoPage);
}
