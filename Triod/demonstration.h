#ifndef PRAKTIKUM_H
#define PRAKTIKUM_H

#include <QWidget>
#include <QLabel>
#include <QtSvg>
#include <QGraphicsScene>
#include "clickablelabel.h"
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
    void back_toMenu();

private slots:
    void on_goMenu_clicked();
    void on_PlusMinus_clicked();
    void on_MinusPlus_clicked();
    void on_ResistGridSlider_valueChanged(int value);
    void on_UoltAnodSlider_valueChanged(int value);

private:
    ElectroChain Chain;
    TriodLamp *TriodDemo;

    // Физические параметры
    Connection connectCur;

    // Параметры отрисовки
    Ui::Demonstration *ui;
    QPixmap *minusPlus = new QPixmap,
            *plusMinus = new QPixmap;

    // Функции отрисовки
    void setConnectionIcons(); // -- загрузка изображений типа подключения --
    void setResistSliderView();// -- установка параметры ползунка сопротивления --
    void setUoltSliderView();  // -- установка параметры ползунка напряжения --
    void setAnodChars();       // -- установка значений анодных характеристик --
    void setGridChars();       // -- установка значений сеточных характеристик --
    void chosenPolar(ClickableLabel &on, ClickableLabel &off);  // -- выбрано подключение --
    void chosenPlusMinus();    // -- выбран тип подключения (+-) --
    void chosenMinusPlus();    // -- выбран тип подключения (-+) --
    void changePhysics();      // -- изменяется напряжение на сетке и сила тока --
};

#endif // PRAKTIKUM_H
