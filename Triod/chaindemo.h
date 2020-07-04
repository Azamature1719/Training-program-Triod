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
#include "electron.h"

class ChainDemo : public QGraphicsScene
{
    Q_OBJECT

public:
    ChainDemo(QRect rect);

    void signal_SEND(LampMode curMode);

private:
     QGraphicsSvgItem *frame;
     Electron *electron;
     QList<Electron*> electroStream;
     QList<QPropertyAnimation*> animaStream,
                                actorsStream;
     QRect *boundaries;
     QTimer *timer;
     static int inter;

     void setupPictures();
     void forwardLamp();
     void sequence_TIMER();

     // Режимы лампы
     void lamp_opened_GO();
     void cur_high_GO();
     void oper_current_GO();
     void cur_low_GO();
     void lamp_closed_GO();

private slots:
     void sequence_GO();
};

#endif // CHAINDEMO_H
