#ifndef TRIODLAMP_H
#define TRIODLAMP_H

#include <QObject>
#include <QPropertyAnimation>
#include <QtSvg>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "commonenum.h"
#include "cloud.h"
#include "lampparam.h"
#include "electron.h"

class TriodLamp : public QGraphicsScene
{
    Q_OBJECT

public:
    TriodLamp(QRect rect);

private:
    void setupPictures();
    void setPlus();
    void setMinus();
    void fillAnimation();

    void allOff();
    void lampClosed();
    void currentLow();
    void operatingCurrent();
    void currentHigh();
    void lampOpened();

public:
    QRect *boundaries,
          *cloudBound;

    void signal_SEND(LampMode mode);
    void changePolar(Connection sign);
    void changeColourCloud(double uoltGrid);

private:
    int error = 5;
    int XStart  = -14;
    int XMedium = -18;

    QSize *electronSize;
    QPixmap *signPix;

    Electron *electron;
    QList<Electron*> electroStream;
    QList<QPropertyAnimation*> animaStream;
    QParallelAnimationGroup *triple,
                            *operClosed,
                            *operLow,
                            *operCur,
                            *operHigh,
                            *operOpened;
    QSequentialAnimationGroup *test;

    QGraphicsSvgItem *frame;
    QGraphicsPixmapItem *sign;
    Cloud *cloud;
    Connection lastConnect;
    QTimer *timer;

signals:
    void go_lamp_opened();
    void go_cur_high();
    void go_oper_current();
    void go_cur_low();
    void go_lamp_closed();

private slots:
    void lamp_opened_GO();
    void cur_high_GO();
    void oper_cur_GO();
    void cur_low_GO();
    void lamp_closed_GO();
};

#endif // TRIODLAMP_H
