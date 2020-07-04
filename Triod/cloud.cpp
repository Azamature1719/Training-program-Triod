#include "cloud.h"

Cloud::Cloud()
{
    anim.setPropertyName("background");   // �������� ��� ��������
    anim.setTargetObject(this);           // �������� ������ �������
    anim.setDuration(700);                // ����������������� �����
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
    anim.setStartValue(background); // �� ������ �����
    anim.setEndValue(newBack);      // � �����
    anim.start();
}
