#ifndef LAMPPARAM_H
#define LAMPPARAM_H

enum class Connection
{
    minus,
    plus
};

class LampParam
{
   int ResistGrid;
   double UoltGrid;
   int Slope;
   int InResist;
   Connection curConnection;

   // ��� ���������� ������������� ������
   double LastUoltGrid;

public:
    LampParam();

    // ���������� ��������� ������
    void SetResistGrid(const int&);
    void SetUoltGrid();
    void SetCurConnection(const Connection&);

    // �������� ��������� ������
    int GetResistGrid();
    double GetUoltGrid();
    int GetCoefficientForce();
    double GetCoefficientA();
    Connection GetCurConnection();

    // ���������� ������-�������� �������������� ������
    int FindSlope();
    int FindForce();
    int FindInResist();

public:
    const double SingleStep = 80.0;
    constexpr static double CoefficientA = 0.0055;
    constexpr static int CoefficientForce = 30;
};

#endif // LAMPPARAM_H
