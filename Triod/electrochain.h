#ifndef ELECTROCHAIN_H
#define ELECTROCHAIN_H

#include "lampparam.h"

class ElectroChain
{
    int UoltAnod;
    double IntenseForce;

    // ���������� �������� ��� ���������� �������������
    int LastUoltAnod;
    double LastIntenseForce;

public:
    ElectroChain();
    void SetUoltAnod(const int&);
    void FindIntenseForce();
    int GetUoltAnod();
    double GetIntenseForce();

public:
    LampParam Lamp;
};

#endif // ELECTROCHAIN_H
