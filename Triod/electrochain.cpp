#include "electrochain.h"
#include <cmath>

#include <QDebug>

ElectroChain::ElectroChain()
    : UoltAnod(30), IntenseForce(), LastUoltAnod(), LastIntenseForce()
{}

void ElectroChain::SetUoltAnod(const int &outUolt)
{
    UoltAnod = outUolt;
}

void ElectroChain::SetLastUoltAnod()
{
    LastUoltAnod = UoltAnod;
}

void ElectroChain::SetLastIntenseForce()
{
    LastIntenseForce = IntenseForce;
}

void ElectroChain::FindIntenseForce()
{
    double innerSum = UoltAnod + Lamp.CoefficientForce * (Lamp.GetUoltGrid()),
           newIntenseForce = Lamp.CoefficientA * pow(innerSum, 1.5);
    if(newIntenseForce != newIntenseForce) newIntenseForce = 0;
    IntenseForce = CorrectFloor(newIntenseForce);
}

void ElectroChain::FindInResist()
{
    double InResist = GetUoltDifference()/GetIntenseDifference();
    Lamp.SetInResist(CorrectFloor(InResist));
}

int ElectroChain::GetUoltAnod()
{
    return UoltAnod;
}

double ElectroChain::GetIntenseForce()
{
    return IntenseForce;
}

int ElectroChain::GetUoltDifference()
{
    return abs(UoltAnod - LastUoltAnod);
}

double ElectroChain::GetIntenseDifference()
{
    double dif = LastIntenseForce - IntenseForce;
    std::cout << "\nLast = " << LastIntenseForce
              << "  Cur = " << IntenseForce
              << "  Dif = " << dif;
    return (CorrectFloor(fabs(dif)));
}

double ElectroChain::CorrectFloor(double value)
{
    return (floor(value * 100 + 0.5) / 100);
}
