#include "lampparam.h"
#include <cmath>

LampParam::LampParam()
    : ResistGrid(), UoltGrid(),Slope(), InResist(), LastUoltGrid()
{}

void LampParam::SetCurConnection(const Connection outConnection)
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
        UoltGrid = CorrectFloor(-(ResistGrid / SingleStep));
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

void LampParam::SetLampMode(const double IntenseForce)
{
    prevCurMode = curMode;

    if(IntenseForce - 0.5 < 0.0001)
    {
        curMode = LampMode::closed;
        return;
    }
    if(IntenseForce - 4 < 0.0001)
    {
        curMode = LampMode::almostClosed;
        return;
    }
    if(IntenseForce - 10 < 0.0001)
    {
        curMode = LampMode::working;
        return;
    }
    if(IntenseForce - 12 < 0.0001)
    {
        curMode = LampMode::almostOpened;
    }
    else
    {
        curMode = LampMode::opened;
    }
}

void LampParam::ChangeLastUoltGrid()
{
    LastUoltGrid = UoltGrid;
}

void LampParam::FindSlope(double DifferenceIntense)
{
    double DifferenceUolt = GetUoltGridDifference();
    double newSlope = CorrectFloor(DifferenceIntense / DifferenceUolt);
    Slope = newSlope;
}

void LampParam::FindForce()
{
    CoForce = Slope*ResistGrid;
}

/// Физические параметры триода
Connection LampParam::GetCurConnection()
{
    return curConnection;
}

LampMode LampParam::GetLampMode()
{
    return curMode;
}

LampMode LampParam::GetPrevLampMode()
{
    return prevCurMode;
}

int LampParam::GetResistGrid()
{
    return ResistGrid;
}

double LampParam::GetUoltGrid()
{
    return UoltGrid;
}

double LampParam::GetLastUoltGrid()
{
    return LastUoltGrid;
}

/// Промежуточные значения для АСХ
double LampParam::GetUoltGridDifference()
{
    double DifferenceGrid = fabs(UoltGrid - LastUoltGrid);
    if(DifferenceGrid == 0) DifferenceGrid = 1;
    return CorrectFloor(DifferenceGrid);
}

/// Анодно-сеточные характеристики
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

/// Округление до двух знаков после запятой
double LampParam::CorrectFloor(double value)
{
    return (floor(value * 100 + 0.5) / 100);
}
