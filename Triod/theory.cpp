#include "theory.h"
#include "ui_theory.h"

Theory::Theory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Theory)
{
    ui->setupUi(this);

    if (!QFile::exists("Files\theory_text.txt"))
    {
        QMessageBox::warning(this,"Ошибка","Не удалось открыть файл theory_text.txt");
    }
    else
    {
        ui->textBrowser->setSource(QUrl("Files\theory_text.txt"));
    }
}

Theory::~Theory()
{
    delete ui;
}

void Theory::on_goMenu_clicked()
{
    emit back_toMenu();
}
