#include "demonstration.h"
#include "ui_demonstration.h"

#include <QGraphicsItem>
#include <QPropertyAnimation>
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
    ElChainDemo = new ChainDemo(ui->graphicsView_2->rect());
    minusPlus = new QGraphicsSvgItem("Files/SVG/MinusPlus.svg");
    plusMinus = new QGraphicsSvgItem("Files/SVG/PlusMinus.svg");

    ui->graphicsView->setScene(TriodDemo);
    ui->graphicsView->setRenderHints(QPainter::RenderHint::HighQualityAntialiasing);
    ui->graphicsView->show();

    ui->graphicsView_2->setScene(ElChainDemo);
    ui->graphicsView->setRenderHints(QPainter::RenderHint::HighQualityAntialiasing);
    ui->graphicsView->show();

    // Выбрано подключение "минус-плюс"
    ui->grViewMinus->setStyleSheet("QGraphicsView {"
                                      "background-color: #B8FFC9;"
                                      "}");

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
    QGraphicsScene *PlusMinus = new QGraphicsScene,
                   *MinusPlus = new QGraphicsScene;
    PlusMinus->addItem(plusMinus);
    MinusPlus->addItem(minusPlus);

    ui->grViewPlus->setScene(PlusMinus);
    ui->grViewPlus->show();

    ui->grViewMinus->setScene(MinusPlus);
    ui->grViewMinus->show();
}

void Demonstration::mousePressEvent(QMouseEvent *event)
{
    QPoint remappedMinus = ui->grViewMinus->mapFromParent(event->pos()),
           remappedPlus  = ui->grViewPlus->mapFromParent(event->pos());

    if (ui->grViewMinus->rect().contains(remappedMinus))
    {
        ui->grViewPlus->setStyleSheet("QGraphicsView {"
                                          "background-color: #FFFFFF;"
                                          "}");
        ui->grViewMinus->setStyleSheet("QGraphicsView {"
                                          "background-color: #B8FFC9;"
                                          "}");
        chosenMinusPlus();
        return;
    }

    if (ui->grViewPlus->rect().contains(remappedPlus))
    {
        ui->grViewMinus->setStyleSheet("QGraphicsView {"
                                          "background-color: #FFFFFF;"
                                          "}");
        ui->grViewPlus->setStyleSheet("QGraphicsView {"
                                          "background-color: #B8FFC9;"
                                          "}");
        chosenPlusMinus();
    }
}

void Demonstration::changePhysics()
{
    // Установить новые значения параметров
    Chain.Lamp.SetUoltGrid();
    Chain.FindIntenseForce();
    Chain.Lamp.SetLampMode(Chain.GetIntenseForce());

    // Изменить значения триода
    ui->UoltGridLbl->setNum(Chain.Lamp.GetUoltGrid());
    TriodDemo->changeColourCloud(Chain.Lamp.GetUoltGrid());
    ElChainDemo->changeColourCloud(Chain.Lamp.GetUoltGrid());

    // Изменить значение силы тока
    ui->IntenseForceLbl->setNum(Chain.GetIntenseForce());

    LampMode curMode = Chain.Lamp.GetLampMode();
    std::string lampState = "";
    switch(curMode)
    {
    case(LampMode::closed):
        lampState = "Лампа заперта";
        break;

    case(LampMode::almostClosed):
        lampState = "Ток ниже рабочего";
        break;

    case(LampMode::working):
        lampState = "Рабочий ток";
        break;

    case(LampMode::almostOpened):
        lampState = "Ток выше рабочего";
        break;

    case(LampMode::opened):
        lampState = "Лампа отперта";
        break;
    }
    ui->LampMode->setText(lampState.c_str());

    if(lastMode != lampState)
        ui->LampMode->startTransitMode(Chain.Lamp.GetCurConnection());
    lastMode = lampState;

    LampMode prevCurMode = Chain.Lamp.GetPrevLampMode();
    if(curMode != prevCurMode)
    {
        emit TriodDemo->signal_SEND(curMode);
        ElChainDemo->signal_SEND(curMode);
    }
}

void Demonstration::setAnodChars()
{
    Chain.FindInResist();
    double newInResist = (Chain.Lamp.GetInResist());

    ui->ResistInUoltAnodLbl->setNum((Chain.GetUoltDifference()));
    ui->ResistInForceIntenseLbl->setNum((Chain.GetIntenseDifference()));

    if(fabs(Chain.GetIntenseForce()) < 0.00001) // Заменить значения, если лампа заперта
        ui->ResistInResultLbl->setText("-");    // Сам InResist при рассчёте заменяется NaN на 0
    else
        ui->ResistInResultLbl->setNum(newInResist);
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
    TriodDemo->changePolar(Connection::minus);
    ui->ResistGridSlider->setRange(0, 400);
    changePhysics();
}

void Demonstration::chosenPlusMinus()
{
    Chain.Lamp.SetCurConnection(Connection::plus);
    TriodDemo->changePolar(Connection::plus);
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

void Demonstration::on_goToMenu_clicked()
{
    ui->goToMenu->startTransitTitles();
    QTimer *timer = new QTimer;
    timer->singleShot(500, this, SIGNAL(back_toMenu()));
}
