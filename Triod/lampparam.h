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
   double Slope;
   double CoForce;
   double InResist;
   Connection curConnection;

   // ��� ���������� ������������� ������
   double LastUoltGrid;

public:
    LampParam();

    // ���������� ��������� ������
    void SetResistGrid(const int&);
    void SetUoltGrid();
    void SetCurConnection(const Connection&);
    void ChangeLastUoltGrid();

    // �������� ��������� ������
    int    GetResistGrid();
    double GetUoltGrid();
    int GetCoefficientForce();
    double GetCoefficientA();
    Connection GetCurConnection();

    // ���������� ������-�������� �������������� ������
    void FindSlope(double DifferenceForce); // ������� �������� �����
    void FindForce(); // ������� ������������ ��������
    void SetInResist(double ChainInResist); // �������������� ������ ������ �����������

    // �������� ������-�������� ��������������
    double GetSlope();
    double GetCoForce();
    double GetInResist();

public:
    const double SingleStep = 80.0;
    constexpr static double CoefficientA = 0.0055;
    constexpr static int CoefficientForce = 30;
};

#endif // LAMPPARAM_H
