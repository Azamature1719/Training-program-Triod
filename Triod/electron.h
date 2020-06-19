#ifndef ELECTRON_H
#define ELECTRON_H

#include <QObject>
#include <QDebug>
#include <QRectF>
#include <QGraphicsPixmapItem>

class Electron : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QRect geometry MEMBER m_geometry READ geometry WRITE setGeometry)

private:
    double lastWidth;
    void setGeometry(QRect newRect);
    QRect geometry();

public:
    explicit Electron(QObject *parent = nullptr);
    int width();
    int height();

signals:

};

#endif // ELECTRON_H
