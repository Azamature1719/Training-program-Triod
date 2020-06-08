#include "lampparam.h"

LampParam::LampParam()
    : ResistGrid(), UoltGrid(),Slope(), InResist(), LastUoltGrid()
{}

void LampParam::SetCurConnection(const Connection &outConnection)
{
    curConnection = outConnection;
}

void LampParam::SetResistGrid(const int &outResist)
{
    ResistGrid = outResist;
}

void LampParam::SetUoltGrid()
{
    if(!ResistGrid)
    {
        UoltGrid = 0;
    }
    else
    {
        UoltGrid = -(ResistGrid / SingleStep);
        if(curConnection == Connection::plus)
        {
            UoltGrid *= -1;
        }
    }
}

void LampParam::SetInResist(double ChainInResist)
{
    InResist = ChainInResist;
}

void LampParam::ChangeLastUoltGrid()
{
    LastUoltGrid = UoltGrid;
}

void LampParam::FindSlope(double DifferenceIntense)
{
    Slope = (DifferenceIntense / (LastUoltGrid - UoltGrid));
}

void LampParam::FindForce()
{
    CoForce = Slope*ResistGrid;
}

Connection LampParam::GetCurConnection()
{
    return curConnection;
}

int LampParam::GetResistGrid()
{
    return ResistGrid;
}

double LampParam::GetUoltGrid()
{
    return UoltGrid;
}

double LampParam::GetSlope()
{
    return Slope;
}

double LampParam::GetCoForce()
{
    return CoForce;
}

double LampParam::GetInResist()
{
    return InResist;
}
