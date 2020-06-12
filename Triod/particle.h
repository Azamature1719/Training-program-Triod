#ifndef PARTICLE_H
#define PARTICLE_H

#include <QObject>

class Particle : public QObject
{
    Q_OBJECT
public:
    explicit Particle(QObject *parent = nullptr);

signals:

};

#endif // PARTICLE_H
