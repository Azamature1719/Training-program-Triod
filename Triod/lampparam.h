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

   // Для вычисления характеристик триода
   double LastUoltGrid;

public:
    LampParam();

    // Установить параметры триода
    void SetResistGrid(const int&);
    void SetUoltGrid();
    void SetCurConnection(const Connection&);
    void ChangeLastUoltGrid();

    // Получить параметры триода
    int    GetResistGrid();
    double GetUoltGrid();
    int GetCoefficientForce();
    double GetCoefficientA();
    Connection GetCurConnection();

    // Рассчитать анодно-сеточные характеристики триода
    void FindSlope(double DifferenceForce); // Рассчёт крутизны лампы
    void FindForce(); // Рассчёт коэффициента усиления
    void SetInResist(double ChainInResist); // Рассчитывается внутри класса ЭлектроЦепь

    // Получить анодно-сеточные характеристики
    double GetSlope();
    double GetCoForce();
    double GetInResist();

public:
    const double SingleStep = 80.0;
    constexpr static double CoefficientA = 0.0055;
    constexpr static int CoefficientForce = 30;
};

#endif // LAMPPARAM_H
