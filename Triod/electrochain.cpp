#include "electrochain.h"
#include <cmath>
ElectroChain::ElectroChain()
    : UoltAnod(30), IntenseForce(), LastUoltAnod(), LastIntenseForce()
{}

void ElectroChain::SetUoltAnod(const int &outUolt)
{
    UoltAnod = outUolt;
}

int ElectroChain::GetUoltAnod()
{
    return UoltAnod;
}

void ElectroChain::FindIntenseForce()
{
    if(Lamp.GetCurConnection() == Connection::plus)
    {
        IntenseForce = 10;
    }

    if(Lamp.GetCurConnection() == Connection::minus)
    {
        double innerSum = UoltAnod + Lamp.CoefficientForce * (Lamp.GetUoltGrid());
        IntenseForce = Lamp.CoefficientA * pow(innerSum, 1.5);
    }
}

double ElectroChain::GetIntenseForce()
{
    return IntenseForce;
}
