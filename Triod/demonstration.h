#ifndef PRAKTIKUM_H
#define PRAKTIKUM_H

#include <QWidget>
#include <QLabel>
#include <QtSvg>
#include <QGraphicsScene>
#include "clickablelabel.h"
#include "chaindemo.h"
#include "commonenum.h"
#include "electrochain.h"
#include "triodlamp.h"

namespace Ui {
class Demonstration;
}

class Demonstration : public QWidget
{
    Q_OBJECT

public:
    explicit Demonstration(QWidget *parent = nullptr);
    ~Demonstration();

signals:
    void minus_plus();
    void plus_minus();
    void back_toMenu();

private slots:
    void on_goToMenu_clicked();
    void on_ResistGridSlider_valueChanged(int value);
    void on_UoltAnodSlider_valueChanged(int value);

private:
    ElectroChain Chain;
    TriodLamp *TriodDemo;
    ChainDemo *ElChainDemo;
    std::string lastMode = "";

    // Физические параметры
    Connection connectCur;

    // Параметры отрисовки
    Ui::Demonstration *ui;
    QGraphicsSvgItem *minusPlus,
                      *plusMinus;

    // Для отслеживания нажатия на тип подключения
    void mousePressEvent(QMouseEvent *event);

    // Функции отрисовки
    void setConnectionIcons(); // Загрузка изображений типа подключения
    void setResistSliderView();// Установка параметры ползунка сопротивления
    void setUoltSliderView();  // Установка параметры ползунка напряжения
    void setAnodChars();       // Установка значений анодных характеристик
    void setGridChars();       // Установка значений сеточных характеристик
    void chosenPolar(ClickableLabel &on, ClickableLabel &off);  // Выбрано подключение
    void chosenPlusMinus();    // Выбран тип подключения (+-)
    void chosenMinusPlus();    // Выбран тип подключения (-+)
    void changePhysics();      // Изменяется напряжение на сетке и сила тока
};

#endif // PRAKTIKUM_H
