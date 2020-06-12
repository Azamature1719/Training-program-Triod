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

    // ���������� ���������
    Connection connectCur;

    // ��������� ���������
    Ui::Demonstration *ui;
    QPixmap *minusPlus = new QPixmap,
            *plusMinus = new QPixmap;

    // ������� ���������
    void setConnectionIcons(); // -- �������� ����������� ���� ����������� --
    void setResistSliderView();// -- ��������� ��������� �������� ������������� --
    void setUoltSliderView();  // -- ��������� ��������� �������� ���������� --
    void setAnodChars();       // -- ��������� �������� ������� ������������� --
    void setGridChars();       // -- ��������� �������� �������� ������������� --
    void chosenPolar(ClickableLabel &on, ClickableLabel &off);  // -- ������� ����������� --
    void chosenPlusMinus();    // -- ������ ��� ����������� (+-) --
    void chosenMinusPlus();    // -- ������ ��� ����������� (-+) --
    void changePhysics();      // -- ���������� ���������� �� ����� � ���� ���� --
};

#endif // PRAKTIKUM_H
