#include "exam.h"
#include "ui_exam.h"

Exam::Exam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exam)
{
    ui->setupUi(this);
}

Exam::~Exam()
{
    delete ui;
}

void Exam::on_goMenu_clicked()
{
    emit back_toMenu();
}
