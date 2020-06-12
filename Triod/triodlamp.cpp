#include "triodlamp.h"
#include <QPropertyAnimation>

TriodLamp::TriodLamp(QRect rect)
    :QGraphicsScene(rect), boundaries(new QRect(rect)), cloudBound(new QRect(55, boundaries->height()/2 - 57, boundaries->width()*0.7, 80))
{
    setupPictures();
}

void TriodLamp::setupPictures()
{
    frame = new QGraphicsSvgItem("Files/SVG/Frame.svg");
    frame->setScale(0.65);
    this->addItem(frame);
    sign = new QGraphicsPixmapItem(*signPix);
    this->addItem(sign);
    setMinus();
    cloud = this->addEllipse(*cloudBound, QPen(Qt::blue), QBrush(Qt::blue));
    electron = this->addPixmap(QPixmap("Files/SVG/Electron.svg"));
}

void TriodLamp::setPlus()
{
    sign->setPixmap(QPixmap("Files/SVG/Plus.svg"));
    sign->setX(cloudBound->x() - 50);
    sign->setY(cloudBound->y());
}

void TriodLamp::setMinus()
{
    sign->setPixmap(QPixmap("Files/SVG/Minus.svg"));
    sign->setX(cloudBound->x() - 50);
    sign->setY(cloudBound->y() + 20);
}

void TriodLamp::forward()
{
   // Electron el;
   // QPropertyAnimation animation(&el, "geometry");
}
