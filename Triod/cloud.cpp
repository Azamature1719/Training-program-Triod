#include "cloud.h"

Cloud::Cloud()
{
    anim.setPropertyName("background");   // свойство для анимации
    anim.setTargetObject(this);           // свойство какого объекта
    anim.setDuration(700);                // продолжительность смены
}

QColor Cloud::getBackground() const
{
    return background;
}

void Cloud::setBackground(const QColor &back)
{
    background = back;
    this->setBrush(QBrush(back, Qt::BrushStyle::Dense3Pattern));
}

void Cloud::startTransit(const QColor &newBack)
{
    anim.setStartValue(background); // из какого цвета
    anim.setEndValue(newBack);      // в какой
    anim.start();
}
