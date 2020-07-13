#include "cloud.h"

Cloud::Cloud()
{
    anim.setPropertyName("background");   // Свойство для анимации
    anim.setTargetObject(this);           // Свойство какого объекта
    anim.setDuration(300);                // Продолжительность смены
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
    anim.setStartValue(background); // Из какого цвета
    anim.setEndValue(newBack);      // В какой
    anim.start();
}
