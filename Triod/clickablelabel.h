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
public:
     explicit ClickableLabel(QWidget* parent = nullptr, const QString& text = "");
    ~ClickableLabel();

    QColor getBackground() const;
    void setBackground(const QColor& back);
    void startTransit(Connection sign);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    QColor background;
    QPropertyAnimation anim;
};

#endif // CLICKABLELABLE_H
