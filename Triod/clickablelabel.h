#ifndef CLICKABLELABLE_H
#define CLICKABLELABLE_H

#include <QLabel>
#include <QPropertyAnimation>
#include <QDebug>
#include <QMouseEvent>
#include "commonenum.h"

namespace Ui {
class ClickableLabel;
}

class ClickableLabel : public QLabel
{
Q_OBJECT

Q_PROPERTY(QColor background
           READ getBackground
           WRITE setBackground)

Q_PROPERTY(QColor frame
           READ getFrame
           WRITE setFrame)
public:
     explicit ClickableLabel(QWidget* parent = nullptr, const QString& text = "");
    ~ClickableLabel();

    QColor getBackground() const;
    void setBackground(const QColor &back);

    QColor getFrame() const;
    void setFrame(const QColor &frame);

    void startTransitTitles();
    void startTransitMode(Connection sign);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);    
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);

private:
    QColor background,
           frame;
    QPropertyAnimation animBackPlus,
                       animBackMinus,
                       animBackChosen,
                       animFrame;
};

#endif // CLICKABLELABLE_H
