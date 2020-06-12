#ifndef TRIODLAMP_H
#define TRIODLAMP_H

#include <QObject>
#include <QtSvg>
#include <QGraphicsScene>
#include <QStateMachine>
#include <QDebug>
#include "commonenum.h"
#include "lampparam.h"

class TriodLamp: public QGraphicsScene
{
    Q_OBJECT

public:
    TriodLamp(QRect rect);

private:
    void setupPictures();
    void setPlus();
    void setMinus();
    void forward();

private:
    QRect *boundaries,
          *cloudBound;
    QPixmap *signPix;
    QState *normal;
    QGraphicsSvgItem *frame;
    QGraphicsPixmapItem *electron;
    QGraphicsPixmapItem *sign;
    QGraphicsEllipseItem *cloud;

};

#endif // TRIODLAMP_H
