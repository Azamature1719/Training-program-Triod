#include "clickablelabel.h"
#include <QColorDialog>

ClickableLabel::ClickableLabel(QWidget* parent, const QString& text)
    : QLabel(parent)
{
    setText(text);

    animBackMinus.setTargetObject(this);
    animBackMinus.setPropertyName("background");
    animBackMinus.setDuration(400);
    animBackMinus.setStartValue("#ffffff");
    animBackMinus.setKeyValueAt(0.5, "#ccccff");
    animBackMinus.setEndValue("#ffffff");

    animBackChosen.setTargetObject(this);
    animBackChosen.setPropertyName("background");
    animBackChosen.setDuration(400);
    animBackChosen.setStartValue("#ffffff");
    animBackChosen.setKeyValueAt(0.5, "#c5e6d1");
    animBackChosen.setEndValue("#ffffff");

    animBackPlus.setTargetObject(this);
    animBackPlus.setPropertyName("background");
    animBackPlus.setDuration(400);
    animBackPlus.setStartValue("#ffffff");
    animBackPlus.setKeyValueAt(0.5, "#ffffad");
    animBackPlus.setEndValue("#ffffff");

    animFrame.setTargetObject(this);
    animFrame.setPropertyName("frame");
    animFrame.setDuration(400);
    animFrame.setStartValue(frame);
    animFrame.setKeyValueAt(0.5, "#ffffad");
    animFrame.setEndValue("#ffffff");

    this->setStyleSheet("QLabel "
                        "{"
                        "border-color: #255737;"
                        "border-radius: 20px;"
                        "border-style: solid;"
                        "border-width: 2px"
                        "}");
}

ClickableLabel::~ClickableLabel(){}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

void ClickableLabel::leaveEvent(QEvent *event)
{
    this->setStyleSheet("QLabel {"
                                "border-color: black;"
                                "border-radius: 20px;"
                                "border-style: solid;"
                                "border-width: 2px;"
                                "background-color: #ffffff;"
                        "}");
}

void ClickableLabel::enterEvent(QEvent *event)
{
    this->setStyleSheet("QLabel {"
                                "border-color: black;"
                                "border-radius: 20px;"
                                "border-style: solid;"
                                "border-width: 4px;"
                                "background-color: #ffffad;"
                        "}");
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

    this->setStyleSheet("QLabel {"
                                "border-color: black;"
                                "border-radius: 20px;"
                                "border-style: solid;"
                                "border-width: 2px;"
                                "background-color:"+colcode+";"
                        "}");
}

QColor ClickableLabel::getFrame() const
{
    return frame;
}

void ClickableLabel::setFrame(const QColor & outframe)
{
    frame = outframe;
    QVariant variant = frame;
    QString colcode = variant.toString();

    qDebug() << colcode;
    this->setStyleSheet("QLabel {border-color:"+colcode+"}");
}

void ClickableLabel::startTransitTitles()
{
    animBackChosen.start();
}

void ClickableLabel::startTransitMode(Connection sign)
{
    switch (sign)
    {
        case Connection::minus:
            animBackMinus.start();
        break;

        case Connection::plus:
            animBackPlus.start();
        break;
    }
}
