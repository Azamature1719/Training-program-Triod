#include "lampparam.h"

LampParam::LampParam()
    : ResistGrid(), UoltGrid(),Slope(), InResist(), LastUoltGrid()
{}

void LampParam::SetResistGrid(const int &outResist)
{
    ResistGrid = outResist;
}

int LampParam::GetResistGrid()
{
    return ResistGrid;
}

void LampParam::SetCurConnection(const Connection &outConnection)
{
    curConnection = outConnection;
}

Connection LampParam::GetCurConnection()
{
    return curConnection;
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

double LampParam::GetUoltGrid()
{
    return UoltGrid;
}

int LampParam::FindSlope()
{

}

int LampParam::FindForce()
{
    return Slope*ResistGrid;
}

int LampParam::FindInResist()
{

}
