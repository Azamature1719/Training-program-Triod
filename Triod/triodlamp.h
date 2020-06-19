#ifndef TRIODLAMP_H
#define TRIODLAMP_H

#include <QObject>
#include <QPropertyAnimation>
#include <QtSvg>
#include <QGraphicsScene>
#include <QStateMachine>
#include <QList>
#include <QDebug>
#include "commonenum.h"
#include "lampparam.h"
#include "electron.h"

class TriodLamp: public QGraphicsScene
{
    Q_OBJECT

public:
    TriodLamp(QRect rect);

private:
    void setupPictures();
    void setPlus();
    void setMinus();
    void fillAnimation();

public:
    QRect *boundaries,
          *cloudBound;
    void animationGo();

private:
    int error = 5;
    QSize *electronSize;
    QPixmap *signPix;

    QState *operatingCurrent;
    QStateMachine *currentFlow;

    Electron *electron;
    QList<Electron*> electroStream;
    QList<QPropertyAnimation*> animaStream;

    QGraphicsSvgItem *frame;
    QGraphicsPixmapItem *sign;
    QGraphicsEllipseItem *cloud;
};

#endif // TRIODLAMP_H
