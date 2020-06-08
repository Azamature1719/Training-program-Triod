#include "demonstration.h"
#include "ui_demonstration.h"

#include <QPainter>
#include <QBitmap>
#include <QDebug>

#include <cmath>

Demonstration::Demonstration(QWidget *parent) : QWidget(parent), ui(new Ui::Demonstration)
{
    ui->setupUi(this);

    // Установить первичные параметры вывода
    setConnectionIcons();
    setResistSliderView();
    setUoltSliderView();
    chosenMinusPlus();
}

Demonstration::~Demonstration()
{
    delete ui;
}

void Demonstration::setConnectionIcons()
{
    minusPlus->load("C:/Qt/INSTITUTE/build-Triod-Desktop_Qt_5_14_0_MinGW_32_bit-Debug/Files/SVG/MinusPlus.svg");
    plusMinus->load("C:/Qt/INSTITUTE/build-Triod-Desktop_Qt_5_14_0_MinGW_32_bit-Debug/Files/SVG/PlusMinus.svg");

    *minusPlus = minusPlus->scaled(30, 180, Qt::KeepAspectRatio);
    *plusMinus = plusMinus->scaled(30, 180, Qt::KeepAspectRatio);

    ui->MinusPlus->setPixmap(*minusPlus);
    ui->PlusMinus->setPixmap(*plusMinus);
}

void Demonstration::chosenPolar(ClickableLabel &on, ClickableLabel &off)
{
    on.setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 2px;"
                                 "border-color: lightgreen; "
                                 "}");
    off.setStyleSheet("QLabel {"
                                 "border-width: 0px;"
                                 "}");
}

void Demonstration::changeAnodGridChar()
{
    Chain.Lamp.SetUoltGrid();
    Chain.FindIntenseForce();

    double newUoltGrid = floor(Chain.Lamp.GetUoltGrid() * 10 + 0.5) / 10,
           newIntenseForce = floor(Chain.GetIntenseForce() * 10 + 0.5) / 10;

    ui->UoltGridLbl->setNum(newUoltGrid);

    if(newIntenseForce != newIntenseForce)
    {
        newIntenseForce = 0;
    }
    ui->IntenseForceLbl->setNum(newIntenseForce);
}

void Demonstration::chosenMinusPlus()
{
    Chain.Lamp.SetCurConnection(Connection::minus);
    chosenPolar(*(ui->MinusPlus), *(ui->PlusMinus));
    ui->ResistGridSlider->setRange(0, 400);
    changeAnodGridChar();
}

void Demonstration::chosenPlusMinus()
{
    Chain.Lamp.SetCurConnection(Connection::plus);
    chosenPolar(*(ui->PlusMinus), *(ui->MinusPlus));
    ui->ResistGridSlider->setRange(0, 160);
    changeAnodGridChar();
}

void Demonstration::setResistSliderView()
{
    ui->ResistGridSlider->setMouseTracking(true);
    ui->ResistGridSlider->setSingleStep(40);
    ui->ResistGridSlider->setTickInterval(40);
    ui->ResistGridSlider->setTickPosition(QSlider::TicksBelow);
    ui->ResistGridLbl->setNum(ui->ResistGridSlider->sliderPosition());
}

void Demonstration::setUoltSliderView()
{
    ui->UoltAnodSlider->setMouseTracking(true);
    ui->UoltAnodSlider->setRange(30, 150);
    ui->UoltAnodSlider->setSingleStep(10);
    ui->UoltAnodSlider->setTickInterval(10);
    ui->UoltAnodSlider->setTickPosition(QSlider::TicksBelow);
}

void Demonstration::on_goMenu_clicked()
{
    emit back_toMenu();
}

void Demonstration::on_MinusPlus_clicked()
{
    chosenMinusPlus();
}

void Demonstration::on_PlusMinus_clicked()
{
    chosenPlusMinus();
}

void Demonstration::on_ResistGridSlider_valueChanged(int value)
{
    Chain.Lamp.SetResistGrid(value);
    ui->ResistGridLbl->setNum(value);
    changeAnodGridChar();
}

void Demonstration::on_UoltAnodSlider_valueChanged(int value)
{
    Chain.SetUoltAnod(value);
    ui->UoltAnodLbl->setNum(value);
    changeAnodGridChar();
}
