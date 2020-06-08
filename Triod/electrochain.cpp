#include "electrochain.h"
#include <cmath>
ElectroChain::ElectroChain()
    : UoltAnod(30), IntenseForce(), LastUoltAnod(), LastIntenseForce()
{}

void ElectroChain::SetUoltAnod(const int &outUolt)
{
    UoltAnod = outUolt;
}

void ElectroChain::ChangeLast()
{
    LastUoltAnod = UoltAnod;
    LastIntenseForce = IntenseForce;
}

void ElectroChain::FindIntenseForce()
{
    double innerSum = UoltAnod + Lamp.CoefficientForce * (Lamp.GetUoltGrid());
    IntenseForce = Lamp.CoefficientA * pow(innerSum, 1.5);
}

void ElectroChain::FindInResist()
{
    double InResist = (UoltAnod - LastUoltAnod)/(IntenseForce - LastIntenseForce);
    Lamp.SetInResist(InResist);
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
    return (UoltAnod - LastUoltAnod);
}

double ElectroChain::GetIntenseDifference()
{
    return (IntenseForce - LastIntenseForce);
}
