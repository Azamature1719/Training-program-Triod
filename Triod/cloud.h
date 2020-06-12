#ifndef CLOUD_H
#define CLOUD_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Cloud:public QGraphicsPixmapItem
{

public:
    Cloud();
    virtual ~Cloud() {}

private:
    QGraphicsEllipseItem *cloud;
    QPixmap *sign;
};

#endif // CLOUD_H
