#ifndef CHAINDEMO_H
#define CHAINDEMO_H

#include <QObject>
#include <QPropertyAnimation>
#include <QtSvg>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "commonenum.h"
#include "lampparam.h"
#include "cloud.h"
#include "electron.h"

class ChainDemo : public QGraphicsScene
{
    Q_OBJECT

public:
    ChainDemo(QRect rect);

    void signal_SEND(LampMode curMode);

    // Изменение облака и знака
    void changeColourCloud(double uoltGrid);

private:
     QGraphicsSvgItem *frame;
     Cloud *cloud;
     QList<Electron*> electroStream;
     QList<QPropertyAnimation*> animaStream,
                                actorsStream;
     QRect *boundaries,
           *cloudBound;
     QTimer *timer;

     static int inter;
     bool wasAdded;
     Connection lastConnect;

     void setupPictures();
     void forwardLamp();
     void sequence_TIMER();
     void addItems();

     /// Режимы лампы
     void lamp_opened_GO();
     void cur_high_GO();
     void oper_current_GO();
     void cur_low_GO();
     void lamp_closed_GO();

private slots:
     void sequence_GO();
};

#endif // CHAINDEMO_H
