#include "theory.h"
#include "ui_theory.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

Theory::Theory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Theory)
{
    ui->setupUi(this);

    if (!QFile::exists("Files/PNG/theory_text.png")   ||
        !QFile::exists("Files/PNG/theory_text_2.png") ||
        !QFile::exists("Files/PNG/theory_text_3.png"))
    {
        QMessageBox::warning(this,"Ошибка","Не удалось найти файлы с теорией");
    }
    else
    {
        scene = new QGraphicsScene(ui->graphicsView->rect());
        scene->setSceneRect(0,0,1000,1100);

        item = new QGraphicsPixmapItem;
        on_first_clicked();

        scene->addItem(item);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->show();
    }
}

Theory::~Theory()
{
    delete ui;
}

void Theory::on_goMenu_clicked()
{
    ui->goMenu->startTransitTitles();
    QTimer *timer = new QTimer;
    timer->singleShot(500, this, SIGNAL(back_toMenu()));
}

void Theory::on_first_clicked()
{
    item->setPixmap(QPixmap("Files/PNG/theory_text.png"));
    ui->first->startTransitTitles();
}

void Theory::on_third_clicked()
{
    item->setPixmap(QPixmap("Files/PNG/theory_text_3.png"));
    ui->third->startTransitTitles();
}

void Theory::on_second_clicked()
{
    item->setPixmap(QPixmap("Files/PNG/theory_text_2.png"));
    ui->second->startTransitTitles();
}
