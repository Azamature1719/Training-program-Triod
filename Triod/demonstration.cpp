#include "demonstration.h"
#include "ui_demonstration.h"

#include <QGraphicsItem>
#include <QPainter>
#include <QBitmap>
#include <QDebug>
#include <QtSvg>
#include <cmath>
#include <iostream>
#include <sstream>

Demonstration::Demonstration(QWidget *parent) : QWidget(parent), ui(new Ui::Demonstration)
{
    ui->setupUi(this);
    TriodDemo = new TriodLamp(ui->graphicsView->rect());
    ui->graphicsView->setScene(TriodDemo);
    ui->graphicsView->setRenderHints(QPainter::RenderHint::HighQualityAntialiasing);
    ui->graphicsView->show();

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

void Demonstration::changePhysics()
{
    // Установить новые значения параметров
    Chain.Lamp.SetUoltGrid();
    Chain.FindIntenseForce();
    Chain.Lamp.SetLampMode(Chain.GetIntenseForce());

    ui->UoltGridLbl->setNum(Chain.Lamp.GetUoltGrid());
    ui->IntenseForceLbl->setNum(Chain.GetIntenseForce());
    ui->LampMode->setText(Chain.Lamp.GetStrLampMode().c_str());
}

void Demonstration::setAnodChars()
{
    Chain.FindInResist();
    double newInResist = (Chain.Lamp.GetInResist());
    ui->ResistInUoltAnodLbl->setNum((Chain.GetUoltDifference()));
    ui->ResistInForceIntenseLbl->setNum((Chain.GetIntenseDifference()));
    if(Chain.GetIntenseForce() == 0)  // Заменить значения, если лампа заперта
    {
        ui->ResistInResultLbl->setText("-");  // Сам InResist при рассчёте заменяется NaN на 0
    }
    else
    {
        ui->ResistInResultLbl->setNum(newInResist);
    }
}

void Demonstration::setGridChars()
{
    Chain.Lamp.FindSlope(Chain.GetIntenseDifference());
    Chain.Lamp.FindForce();

    double newSlope = (Chain.Lamp.GetSlope()),
           newForce = (Chain.Lamp.GetCoForce());

    // Установить промежуточные значения
    ui->SlopeIntenseLbl->setNum((Chain.GetIntenseDifference()));
    ui->SlopeUoltLbl->setNum((Chain.Lamp.GetUoltGridDifference()));

    ui->ForceResistLbl->setNum(Chain.Lamp.GetResistGrid());
    ui->ForceSlopeLbl->setNum(newSlope);

    // Установить результаты
    ui->SlopeResultLbl->setNum(newSlope);
    ui->ForceResultLbl->setNum(newForce);
}

void Demonstration::chosenMinusPlus()
{
    Chain.Lamp.SetCurConnection(Connection::minus);
    chosenPolar(*(ui->MinusPlus), *(ui->PlusMinus));
    ui->ResistGridSlider->setRange(0, 400);
    changePhysics();
}

void Demonstration::chosenPlusMinus()
{
    Chain.Lamp.SetCurConnection(Connection::plus);
    chosenPolar(*(ui->PlusMinus), *(ui->MinusPlus));
    ui->ResistGridSlider->setRange(0, 160);
    changePhysics();
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
    Chain.SetLastIntenseForce();
    Chain.Lamp.ChangeLastUoltGrid();

    Chain.Lamp.SetResistGrid(value);
    ui->ResistGridLbl->setNum(value);
    changePhysics();
    setGridChars();
}

void Demonstration::on_UoltAnodSlider_valueChanged(int value)
{
    Chain.SetLastUoltAnod();
    Chain.SetLastIntenseForce();

    Chain.SetUoltAnod(value);
    ui->UoltAnodLbl->setNum(value);
    changePhysics();
    setAnodChars();
}

void Demonstration::on_pushButton_clicked()
{
    TriodDemo->animationGo();
    ui->graphicsView->setScene(TriodDemo);
    ui->graphicsView->show();
}
