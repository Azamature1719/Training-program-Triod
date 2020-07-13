#include "triodlamp.h"
#include "demonstration.h"
#include <QStateMachine>
#include <QState>

TriodLamp::TriodLamp(QRect rect)
    :QGraphicsScene(rect),
     boundaries(new QRect(rect)),
     cloudBound(new QRect(55, boundaries->height()/2 - 57, boundaries->width()*0.7, 80)),
     electronSize(new QSize(10, 10))
{
    electron   = new Electron;
    cloud      = new Cloud;
    triple     = new QParallelAnimationGroup;
    operCur    = new QParallelAnimationGroup;
    operClosed = new QParallelAnimationGroup;
    operLow    = new QParallelAnimationGroup;
    operHigh   = new QParallelAnimationGroup;
    test = new QSequentialAnimationGroup;
    operOpened = new QParallelAnimationGroup;

    setupPictures();
    fillAnimation();
    lastConnect = Connection::minus;
    timer = new QTimer();

    connect(this, SIGNAL(go_lamp_closed()), this, SLOT(lamp_closed_GO()));
    connect(this, SIGNAL(go_cur_low()), this, SLOT(cur_low_GO()));
    connect(this, SIGNAL(go_oper_current()), this, SLOT(oper_cur_GO()));
    connect(this, SIGNAL(go_cur_high()), this, SLOT(cur_high_GO()));
    connect(this, SIGNAL(go_lamp_opened()), this, SLOT(lamp_opened_GO()));
}

void TriodLamp::setupPictures()
{
    frame = new QGraphicsSvgItem("Files/SVG/Frame.svg");
    frame->setScale(0.65);
    this->addItem(frame);

    sign = new QGraphicsPixmapItem();
    this->addItem(sign);
    setMinus();

    cloud->setPen(QColor(Qt::transparent));
    cloud->setRect(*cloudBound);
    this->addItem(cloud);
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
    for (size_t j = 0; j < 7; ++j)
    {
        Electron *elec = new Electron;
        electroStream.push_back(elec);
        this->addItem(elec);

        QPropertyAnimation *anim = new QPropertyAnimation(elec, "geometry");
        anim->setEasingCurve(QEasingCurve::Linear);
        animaStream.push_back(anim);
    }

    for(int j = 0; j < 7; ++j)
    {
        triple->addAnimation(animaStream[j]);
    }

    operLow->setLoopCount(-1);
    operHigh->setLoopCount(-1);
    operOpened->setLoopCount(-1);
    operClosed->setLoopCount(-1);
    operCur->setLoopCount(-1);
}

void TriodLamp::lampClosed()
{
    int xStart = XStart;
    for(int i = 0; i < animaStream.size(); ++i)
    {
        if(i == 0 || i == 6)
            animaStream[i]->setDuration(200 + rand()%1000);
        else
            animaStream[i]->setDuration(100 + rand()%1000);

        if(i == 0)
        {
            animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 17*error, 20, 20));
            animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 17*error, 20, 20));
        }
        else if(i == 1)
        {
            animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 14*error, 20, 20));
            animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 14*error, 20, 20));
        }
        else if(i == 5)
        {
            animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 14*error, 20, 20));
            animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 14*error, 20, 20));
        }
        else if(i == 6)
        {
            animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error - 6, boundaries->height()/2 + 17*error, 20, 20));
            animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error - 6, boundaries->height()/2 + 17*error, 20, 20));
        }
        else
        {
            animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 20, 20));
            animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 20, 30));
        }

        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 9*error, 20, 20));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 4*error, 20, 20));
        xStart += 5;
    }
    operClosed->addAnimation(triple);
}

void TriodLamp::currentLow()
{
    int xStart = XStart, xMedium = XMedium + 6;
    for(int i = 0; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setDuration(300 + rand()%1000);
        if(i == 0)
        {
            animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 17*error, 20, 20));
            animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 17*error, 20, 20));
        }
        else if(i == 6)
        {
            animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error - 6, boundaries->height()/2 + 17*error, 20, 20));
            animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error - 6, boundaries->height()/2 + 17*error, 20, 20));
        }
        else
        {
           animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 10*error, 20, 20));
           animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 10*error, 20, 20));
        }
        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 5*error, 20, 20));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2, 20, 20));
        xStart += 10;
    }

    xStart = -4;
    for(int i = 1; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setDuration(500 + rand()%2000);
        animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 10, 10));
        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 10*error, electron->width(), electron->height()));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + 2*error, electron->height() + 5*error, 10, 10));
        animaStream[i]->setEndValue(QRect(boundaries->width()/2 + 2*error, (-1)*(8+rand()%10), 10, 10));
        xStart += 10;
        xMedium += 12;
    }
    operLow->addAnimation(triple);
}

void TriodLamp::operatingCurrent()
{
    int xStart = XStart, xMedium = XMedium;

    for(int i = 0; i < animaStream.size(); ++i)
    {
        animaStream[i]->setDuration(200 + rand()%2000);
        animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 10, 10));
        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 10*error, electron->width(), electron->height()));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + 2*error, electron->height() + 7*error, 10, 10));
        animaStream[i]->setEndValue(QRect(boundaries->width()/2 + 2*error, (-1)*(8+rand()%10), 10, 10));
        xStart += 5;
        xMedium += 6;
    }
    operCur->addAnimation(triple);
}

void TriodLamp::currentHigh()
{
    int xStart = XStart + 3,
        xMedium = XMedium + 2;

    for(int i = 0; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setDuration(500 + rand()%500);
        animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 5*error, 20, 20));
        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 12*error, 20, 20));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + xMedium*error,  boundaries->height()/2 + 2*error, 20, 20));
        animaStream[i]->setEndValue(QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 5*error, 20, 20));
        xStart += 10;
        xMedium += 11;
    }

    xStart  = XStart + 5;
    xMedium = XMedium + 6;
    for(int i = 1; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setDuration(500 + rand()%1000);
        animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 10, 10));
        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 10*error, electron->width(), electron->height()));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + 2*error, electron->height() + 5*error, 10, 10));
        animaStream[i]->setEndValue(QRect(boundaries->width()/2 + 2*error, (-1)*(8+rand()%10), 10, 10));
        xStart += 10;
        xMedium += 12;
    }
    operHigh->addAnimation(triple);
}

void TriodLamp::lampOpened()
{
    int xStart = XStart + 3,
    xMedium = XMedium + 2;

    for(int i = 0; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setDuration(500 + rand()%1500);
        animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 10, 10));
        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 10*error, 30, 30));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 5*error, 30, 30));
        animaStream[i]->setEndValue(QRect((-1)*(8+rand()%10), boundaries->height()/2 - 5*error, 10, 10));
        xStart += 10;
        xMedium += 11;
    }

    xStart  = XStart + 5;
    xMedium = XMedium + 6;
    for(int i = 1; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setDuration(500 + rand()%2000);
        animaStream[i]->setStartValue(QRect(boundaries->width()/2 + xStart*error, boundaries->height()/2 + 12*error, 10, 10));
        animaStream[i]->setKeyValueAt(0.4, QRect(boundaries->width()/2 + xMedium*error, boundaries->height()/2 - 10*error, electron->width(), electron->height()));
        animaStream[i]->setKeyValueAt(0.7, QRect(boundaries->width()/2 + 2*error, electron->height() + 5*error, 10, 10));
        animaStream[i]->setEndValue(QRect(boundaries->width()/2 + 2*error, (-1)*(8+rand()%10), 10, 10));
        xStart += 10;
        xMedium += 12;
    }
    operOpened->addAnimation(triple);
}

/// Пускатель сигналов
void TriodLamp::signal_SEND(LampMode curMode)
{
    switch(curMode)
    {
    case(LampMode::closed):
        emit go_lamp_closed();
        return;

    case(LampMode::almostClosed):
        emit go_cur_low();
        return;

    case(LampMode::working):
        emit go_oper_current();
        return;

    case(LampMode::almostOpened):
        emit go_cur_high();
        return;

    case(LampMode::opened):
        emit go_lamp_opened();
        return;
    }
}


void TriodLamp::changePolar(Connection sign)
{
    if(sign != lastConnect)
    {
        switch(sign)
        {
        case Connection::plus:
            setPlus();
            break;

        case Connection::minus:
            setMinus();
            break;
        }
        lastConnect = sign;
    }
}

void TriodLamp::changeColourCloud(double uoltGrid)
{
    int red = 255, green = 255, blue = 255;
    QColor neededColor;

    if(uoltGrid <= 0)
        neededColor = (QColor::fromRgb(red + int(uoltGrid*100/2), green + int(uoltGrid*100/2), blue));

    if(uoltGrid > 0)
        neededColor = (QColor::fromRgb(red, green, blue - int(uoltGrid*127.5)));

    cloud->startTransit(neededColor);
}

void TriodLamp::lamp_closed_GO()
{
    lampClosed();
    operClosed->start();
}

void TriodLamp::cur_low_GO()
{
    currentLow();
    operLow->start();
}

void TriodLamp::oper_cur_GO()
{
    operatingCurrent();
    operCur->start();
}

void TriodLamp::cur_high_GO()
{
    currentHigh();
    operHigh->start();
}

void TriodLamp::lamp_opened_GO()
{
    lampOpened();
    operOpened->start();
}
