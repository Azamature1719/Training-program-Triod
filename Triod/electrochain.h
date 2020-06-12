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
    void SetLastUoltAnod();
    void SetLastIntenseForce();

    void FindIntenseForce();
    void FindInResist(); // ������� ����������� ������������� �����, ��������� ���������� � Lamp.ResistIn

    int  GetUoltAnod();
    double GetIntenseForce();
    double CorrectFloor(double value);

    // �������� ������� �������� �������� � �������� ��������
    int  GetUoltDifference();
    double GetIntenseDifference();

public:
    LampParam Lamp;
};

#endif // ELECTROCHAIN_H
