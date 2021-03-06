#include "chaindemo.h"

int ChainDemo::inter = 0;

ChainDemo::ChainDemo(QRect rect):
    QGraphicsScene(rect),
    boundaries(new QRect(rect)),
    cloudBound(new QRect(boundaries->width()/2 - 70, boundaries->height()/2 - 45, boundaries->width()/6, 30))
{
    cloud = new Cloud;
    timer = new QTimer;

    wasAdded = false;
    setupPictures();
    forwardLamp();
    cur_high_GO();
    sequence_TIMER();
    connect(timer, SIGNAL(timeout()), this, SLOT(sequence_GO()));
}

void ChainDemo::setupPictures()
{
    cloud->setPen(QColor(Qt::transparent));
    cloud->setRect(*cloudBound);
    this->addItem(cloud);

    frame = new QGraphicsSvgItem("Files/SVG/FrameChain.svg");
    frame->setScale(0.75);
    this->addItem(frame);
}


void ChainDemo::changeColourCloud(double uoltGrid)
{
    int red = 255, green = 255, blue = 255;
    QColor neededColor;

    if(uoltGrid <= 0)
        neededColor = (QColor::fromRgb(red + int(uoltGrid*100/2), green + int(uoltGrid*100/2), blue));

    if(uoltGrid > 0)
        neededColor = (QColor::fromRgb(red, green, blue - int(uoltGrid*127.5)));

    cloud->startTransit(neededColor);
}

void ChainDemo::forwardLamp()
{
    for(size_t i = 0; i < 15; ++i)
    {
        Electron *elec = new Electron;
        electroStream.push_back(elec);
        QPropertyAnimation *particleGo = new QPropertyAnimation(elec, "geometry");
        particleGo->setDuration(2000);
        particleGo->setEasingCurve(QEasingCurve::Linear);
        particleGo->setStartValue(QRect(boundaries->width() - 50, boundaries->height()/2, 12, 12));
        particleGo->setKeyValueAt(0.11, QRect(boundaries->width() - 50, boundaries->height() - 75, 12, 12));
        particleGo->setKeyValueAt(0.33, QRect(boundaries->width()/2 - 12, boundaries->height() - 75, 12, 12));
        particleGo->setKeyValueAt(0.44, QRect(boundaries->width()/2 - 12, boundaries->height()/2 + 10, 12, 12));
        animaStream.push_back(particleGo);
    }
}

void ChainDemo::sequence_TIMER()
{
    timer->setInterval(200);
    timer->start();
}

void ChainDemo::sequence_GO()
{
    animaStream[ChainDemo::inter]->start();
    if(!wasAdded) this->addItem(electroStream[ChainDemo::inter]);

    ChainDemo::inter++;
    if(ChainDemo::inter == animaStream.size())
    {
        ChainDemo::inter = 0;
        wasAdded = true;
    }
}

/// ��������� ��������
void ChainDemo::signal_SEND(LampMode curMode)
{
    switch(curMode)
    {
    case(LampMode::closed):
        lamp_closed_GO();
        return;

    case(LampMode::almostClosed):
        cur_low_GO();
        return;

    case(LampMode::working):
        oper_current_GO();
        return;

    case(LampMode::almostOpened):
        cur_high_GO();
        return;

    case(LampMode::opened):
        lamp_opened_GO();
        return;
    }
}

/// ��������� ���������� ������
void ChainDemo::lamp_opened_GO()
{
    for(int i = 0; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 15, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%40, boundaries->height()/2 - 20, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/2 - 30, boundaries->height()/12, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width() - 60, boundaries->height()/12, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width() - 50, boundaries->height(), 0, 0));
    }

    for(int i = 1; i < animaStream.size(); i+=2)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 15, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%40, boundaries->height()/2 - 20, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/3, boundaries->height()/2 - 35, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width()/4 + 17, boundaries->height()/2 - 35, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width()/4 + 20, boundaries->height() - 30, 0, 0));
    }
}

void ChainDemo::cur_high_GO()
{
    for(int i = 0; i < animaStream.size(); i++)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 15, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%40, boundaries->height()/2 - 20, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/2 - 30, boundaries->height()/12, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width() - 60, boundaries->height()/12, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width() - 50, boundaries->height(), 0, 0));
    }

    for(int i = 0; i < animaStream.size(); i+=5)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 15, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%40, boundaries->height()/2 - 20, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/3, boundaries->height()/2 - 35, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width()/4 + 17, boundaries->height()/2 - 35, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width()/4 + 20, boundaries->height() - 30, 0, 0));
    }
}

void ChainDemo::oper_current_GO()
{
    for(int i = 0; i < animaStream.size(); i++)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 15, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%40, boundaries->height()/2 - 20, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/2 - 30, boundaries->height()/12, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width() - 60, boundaries->height()/12, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width() - 50, boundaries->height(), 0, 0));
    }
}

void ChainDemo::cur_low_GO()
{
    for(int i = 0; i < animaStream.size(); i++)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%50, boundaries->height()/2 + 5, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 10, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 12, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 5, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width()/2 - 40, boundaries->height()/2 + 10, 0, 0));
    }

    for(int i = 1; i < animaStream.size(); i+=5)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 15, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%40, boundaries->height()/2 - 20, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/2 - 30, boundaries->height()/12, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width() - 60, boundaries->height()/12, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width() - 50, boundaries->height(), 0, 0));
    }
}

void ChainDemo::lamp_closed_GO()
{
    for(int i = 0; i < animaStream.size(); ++i)
    {
        animaStream[i]->setKeyValueAt(0.55, QRect(boundaries->width()/2 - rand()%50, boundaries->height()/2 + 5, 12, 12));
        animaStream[i]->setKeyValueAt(0.66, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 10, 12, 12));
        animaStream[i]->setKeyValueAt(0.77, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 12, 12, 12));
        animaStream[i]->setKeyValueAt(0.88, QRect(boundaries->width()/2 - rand()%70, boundaries->height()/2 - 5, 12, 12));
        animaStream[i]->setEndValue(QRect(boundaries->width()/2 - 40, boundaries->height()/2 + 10, 0, 0));
    }
}
