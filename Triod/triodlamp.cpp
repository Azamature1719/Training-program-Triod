#include "triodlamp.h"
#include <QRadialGradient>
#include <QPropertyAnimation>
#include <QSize>

TriodLamp::TriodLamp(QRect rect)
    :QGraphicsScene(rect), boundaries(new QRect(rect)),
     cloudBound(new QRect(55, boundaries->height()/2 - 57, boundaries->width()*0.7, 80)),
     electronSize(new QSize(10, 10))
{
    electron = new Electron;
    currentFlow = new QStateMachine;

    setupPictures();
    animationGo();
}

void TriodLamp::setupPictures()
{
    frame = new QGraphicsSvgItem("Files/SVG/Frame.svg");
    frame->setScale(0.65);
    this->addItem(frame);

    sign = new QGraphicsPixmapItem();
    this->addItem(sign);
    setMinus();

    cloud = this->addEllipse(*cloudBound, QPen(Qt::transparent), QBrush(QColor::fromRgb(255, 255, 0),Qt::BrushStyle::Dense4Pattern));
}

void TriodLamp::setPlus()
{
    sign->setPixmap(QPixmap("Files/SVG/Plus.svg"));
    sign->setX(cloudBound->x() - 10*error);
    sign->setY(cloudBound->y());
}

void TriodLamp::setMinus()
{
    sign->setPixmap(QPixmap("Files/SVG/Minus.svg"));
    sign->setX(cloudBound->x() - 10*error);
    sign->setY(cloudBound->y() + 4*error);
}

void TriodLamp::fillAnimation()
{
    for(size_t i = 0; i < 3; ++i)
    {
        int xStart = -14, xMedium = -18;
        for (size_t j = 0; j < 5; ++j)
        {
            Electron *elec = new Electron;
            electroStream.push_back(elec);
            this->addItem(elec);

            QPropertyAnimation *anim = new QPropertyAnimation(elec, "geometry");
            anim->setDuration(400 + rand()%1000);
            anim->setEasingCurve(QEasingCurve::Linear);
            anim->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 10, 10));
            anim->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 10*error, electron->width(), electron->height()));
            anim->setKeyValueAt(0.7, QRect(boundaries->width()/2 + 2*error, electron->height() + 10*error, 10, 10));
            anim->setEndValue(QRect(boundaries->width()/2 + 2*error, -10, 10, 10));

            animaStream.push_back(anim);
            xStart += 5;
            xMedium += 9;
        }
    }
}



void TriodLamp::animationGo()
{
    QParallelAnimationGroup *triple = new QParallelAnimationGroup,
                            *triple2 = new QParallelAnimationGroup,
                            *triple3 = new QParallelAnimationGroup;
    fillAnimation();

    for(int j = 0; j < 5; ++j)
    {
        triple->addAnimation(animaStream[j]);
        qDebug() << j;
    }
    for(int j = 5; j < 10; ++j)
    {
        triple2->addAnimation(animaStream[j]);
        qDebug() << j;
    }
    for(int j = 10; j < 15; ++j)
    {
        triple3->addAnimation(animaStream[j]);
        qDebug() << j;
    }

    QSequentialAnimationGroup *forward = new QSequentialAnimationGroup;
    forward->addAnimation(triple);
    forward->addAnimation(triple2);
    forward->addAnimation(triple3);
    forward->setLoopCount(1000);
    forward->start();
}

