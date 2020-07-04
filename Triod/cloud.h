#ifndef CLOUD_H
#define CLOUD_H

#include <QObject>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Cloud : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

    Q_PROPERTY(QColor background
               READ getBackground
               WRITE setBackground)

public:
    Cloud();
    virtual ~Cloud() {}

    QColor getBackground() const;
    void setBackground(const QColor& back);
    void startTransit(const QColor& newBack);

private:
    QColor background;
    QPropertyAnimation anim;
};

#endif // CLOUD_H
