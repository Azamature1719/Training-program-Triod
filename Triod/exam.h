#ifndef EXAM_H
#define EXAM_H

#include <QWidget>
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class Exam;
}

class Exam : public QWidget
{
    Q_OBJECT

    // ��� �������
    static const int closed_answer = 1, open_answer = 2;

    // ��������� ������ �����
    struct answer
    {
        QString condition;        // ����� ������
        bool correctness = false; // ������������ ������
    };

    // ��������� ������ �� ������ (������� �� ���� �������)
    struct answer_types
    {
        std::vector<int> cb_answer;       // �������� ������
        std::vector<QString> open_answer; // �������� ������
    };

    // ��������� ������� �����
    struct question
    {
        int type = closed_answer;
        QString text = "";
        std::array<answer, 3> variants;
    };

    std::string questionnaire;
    std::vector<question> test_questions;
    answer_types answers;
    size_t number_of_questions = 0;
    size_t step = 0;

signals:
    void back_toMenu(); // ��������� � ������� ����

public:
    explicit Exam(QWidget *parent = nullptr);
    ~Exam();

    void display_question(); // ����� ������� �����
    void display_result();   // ����� ����������� �����
    int check(std::vector<bool> &correct); // ������� �������� ��������
    std::string read_testFile(const std::string &filename); // �������, ����������� ������� �����
    void begin_test();       // �������, ����������� ������������
    void make_question();    // ������� ������������ �������

private slots:

    void on_beginTest_clicked();    // ������ ����
    void on_backToMenu_clicked();   // ��������� � ������� ����
    void on_backToMenu_2_clicked(); // ��������� � ���� ������������ �� �����
    void on_backToMenu_4_clicked(); // ������� � ���� ������������ �� ���� �����������
    void on_conclude_clicked();     // ���������� ������������
    void on_previous_clicked();     // ������� � ����������� �������
    void on_next_clicked();         // ������� � ���������� �������
    void on_numOfQuest_valueChanged(int arg1);// ��������� ��������� ���������� ��������
    void on_choice1_clicked();      // ���� ��� ������ ������ �����
    void on_choice2_clicked();      // ���� ��� ������ ������ �����
    void on_choice3_clicked();      // ���� ��� ������ ������ �����
    void on_answerOpen_textEdited(const QString &arg1);// ���� ��� ����� ����� �� �������� ������

private:
    Ui::Exam *ui;
};

#endif // EXAM_H
