#include "clickablelabel.h"
#include <QColorDialog>

ClickableLabel::ClickableLabel(QWidget* parent, const QString& text)
    : QLabel(parent)
{
    setText(text);
    anim.setTargetObject(this);
    anim.setPropertyName("background");
    anim.setDuration(700);
    anim.setStartValue("#ffffff");
    anim.setEndValue("#ffffff");
}

ClickableLabel::~ClickableLabel(){}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

QColor ClickableLabel::getBackground() const
{
    return background;
}

void ClickableLabel::setBackground(const QColor &back)
{
    background = back;
    QVariant variant = background;
    QString colcode = variant.toString();
    this->setStyleSheet("QLabel { background-color :"+colcode+"}");
}

void ClickableLabel::startTransit(Connection sign)
{
    if(sign == Connection::plus)
        anim.setKeyValueAt(0.5, "#ffffad");
    if(sign == Connection::minus)
        anim.setKeyValueAt(0.5, "#ccccff");

    anim.start();
}
