#include "demonstration.h"
#include "ui_demonstration.h"

Demonstration::Demonstration(QWidget *parent) : QWidget(parent), ui(new Ui::Demonstration)
{
    ui->setupUi(this);
}

Demonstration::~Demonstration()
{
    delete ui;
}

void Demonstration::on_goMenu_clicked()
{
    emit back_toMenu();
}
