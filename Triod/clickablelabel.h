#ifndef CLICKABLELABLE_H
#define CLICKABLELABLE_H

#include <QLabel>
#include <QMouseEvent>

namespace Ui {
class ClickableLabel;
}

class ClickableLabel : public QLabel
{
Q_OBJECT

public:
     explicit ClickableLabel(QWidget* parent = nullptr, const QString& text = "");
    ~ClickableLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABLE_H
