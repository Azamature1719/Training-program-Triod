#ifndef ELECTROCHAIN_H
#define ELECTROCHAIN_H

#include "lampparam.h"

class ElectroChain
{
    int UoltAnod;
    double IntenseForce;

    // Предыдущие значения для вычисления характеристик
    int LastUoltAnod;
    double LastIntenseForce;

public:
    ElectroChain();
    void SetUoltAnod(const int&);
    void ChangeLast();
    void FindIntenseForce();
    void FindInResist(); // Рассчёт внутреннего сопротивления лампы, результат помещается в Lamp.ResistIn
    int  GetUoltAnod();
    double GetIntenseForce();

    // Получить разницу значений текущего и прошлого значений
    int  GetUoltDifference();
    double GetIntenseDifference();

public:
    LampParam Lamp;
};

#endif // ELECTROCHAIN_H
