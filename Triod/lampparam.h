#ifndef LAMPPARAM_H
#define LAMPPARAM_H

#include <iostream>
#include "commonenum.h"

class LampParam
{
   int ResistGrid;
   double UoltGrid;

   double Slope;
   double CoForce;
   double InResist;
   Connection curConnection;
   LampMode curMode;
   std::string strCurMode;

   // Для вычисления характеристик триода
   double LastUoltGrid;

public:
    LampParam();

    // Установить параметры триода
    void SetResistGrid(const int&);
    void SetUoltGrid();
    void SetCurConnection(const Connection);
    void SetLampMode(const double IntenseForce);
    void ChangeLastUoltGrid();

    // Получить параметры триода
    Connection  GetCurConnection();
    LampMode    GetLampMode();
    std::string GetStrLampMode();
    int    GetResistGrid();
    double GetUoltGrid();
    int    GetCoefficientForce();
    double GetCoefficientA();

    // Рассчитать анодно-сеточные характеристики триода
    void FindSlope(double DifferenceForce); // Рассчёт крутизны лампы
    void FindForce();                       // Рассчёт коэффициента усиления
    void SetInResist(double ChainInResist); // Рассчитывается внутри класса ЭлектроЦепь

    // Промежуточные значения АСХ
    double GetUoltGridDifference();

    // Получить анодно-сеточные характеристики
    double GetSlope();
    double GetCoForce();
    double GetInResist();

    // Вспомогательные функции
    double CorrectFloor(double value);

public:
    const double SingleStep = 80.0;
    constexpr static double CoefficientA = 0.0055;
    constexpr static int CoefficientForce = 30;
};

#endif // LAMPPARAM_H
