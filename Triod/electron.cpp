#include "electron.h"

Electron::Electron(QObject *parent) : QObject(parent)
{
    this->setPixmap(QPixmap("Files/SVG/Electron.svg"));
    lastWidth = this->width();
}

int Electron::width()
{
    return pixmap().width();
}

int Electron::height()
{
    return pixmap().height();
}

void Electron::setGeometry(QRect newRect)
{
    this->setX(newRect.x());
    this->setY(newRect.y());
    this->setScale(newRect.width()/lastWidth);
}

QRect Electron::geometry()
{
    return QRect(this->x(), this->y(), width(), height());
}
