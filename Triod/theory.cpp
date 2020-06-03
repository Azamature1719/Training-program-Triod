#include "theory.h"
#include "ui_theory.h"

Theory::Theory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Theory)
{
    ui->setupUi(this);
}

Theory::~Theory()
{
    delete ui;
}

void Theory::on_goMenu_clicked()
{
    emit back_toMenu();
}
