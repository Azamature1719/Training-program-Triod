#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, const QString& text)
    : QLabel(parent)
{
    setText(text);
}

ClickableLabel::~ClickableLabel()
{

}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
