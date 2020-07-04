#include <string>
#include <sstream>
#include <ctime>
#include <QMessageBox>
#include <QRegExpValidator>
#include <random>
#include <fstream>
#include "exam.h"
#include "ui_exam.h"

using namespace std;

Exam::Exam(QWidget *parent) :
    QWidget(parent), ui(new Ui::Exam)
{
    ui->setupUi(this);
    number_of_questions = 5;         // ���������� �������� - 5
    ui->numOfQuest->setRange(5, 10); // � spinbox ���������� ��� � ���� �������� �����
    questionnaire = read_testFile("Files/questions.txt"); // ������� � ���� ������ ��� �������
}

Exam::~Exam()
{
    delete ui;
}

/** ******************************************************************************* **/
// ������� ���� � ���������
string Exam::read_testFile(const std::string &filename)
{
   std::ifstream testFile(filename);
   if (testFile)
   {
       std::ostringstream text;
       text << testFile.rdbuf();
       return text.str();
   }
   else
   {
       return " ";
   }
}

/** ******************************************************************************* **/
// ������ ���������� ������������
void Exam::begin_test()
{
    time_t seed = time(nullptr);
    mt19937 mt(seed);

    // �������� ��� ����, ������� ����������� �� ����� ����������� �����
    test_questions.clear();
    answers.cb_answer.clear();
    answers.open_answer.clear();
    ui->listWidget->clear();
    step = 0;

    // ������� ������
    make_question();

    // ���������� ��� �������
    shuffle(test_questions.begin(),test_questions.end(),mt);

    // ��������� ������� �� ������� ������� � �������� �������
    for (question &quest : test_questions)
    {
        // ���� ������ ��������� ����, ���������� �������� �������
        if (quest.type == closed_answer)
        {
            shuffle(quest.variants.begin(),quest.variants.end(),mt);
        }
    }

    // ������� ������ �� �����
    display_question();
}

/** ******************************************************************************* **/
// ����� ������� �� �����
void Exam::display_question()
{
    ui->textQuestiom->setText(test_questions[step].text);

    switch (test_questions[step].type)
    {
        case closed_answer:
        {
            ui->QuestionTypes->setCurrentWidget(ui->close);
            ui->answer1T->setText(test_questions[step].variants[0].condition);
            ui->answer2T->setText(test_questions[step].variants[1].condition);
            ui->answer3T->setText(test_questions[step].variants[2].condition);
            ui->choice1->setChecked(false);
            ui->choice2->setChecked(false);
            ui->choice3->setChecked(false);
        }
        break;

        case open_answer:
        {
            ui->QuestionTypes->setCurrentWidget(ui->open);
            ui->answerOpen->setText(answers.open_answer[step]);
        }
        break;
    }
}

/** ******************************************************************************* **/
// ������� ����������� �������
void Exam::make_question()
{
    string temp_string; // ������� ������
    question buf;       // �������� ������

    stringstream ss(questionnaire);
    while (getline(ss, temp_string))
    {
        buf.type = temp_string[1] - '0'; // ������� ��� �������
        buf.text = QString::fromStdString({temp_string.begin()+2, temp_string.end()});

        switch (buf.type) // ������� � ���������������� ����� � ����������� �� ���� �������
        {
            case closed_answer: // ���� ������ ��������� ����
            {
                buf.variants[0].correctness = true; // ������ ����� ������ ������
                for (size_t i=0; i < 3; ++i) // ������� ��� �������� ������ �� ������
                {
                    getline(ss, temp_string);
                    buf.variants[i].condition = QString::fromStdString(temp_string);
                }
                answers.cb_answer.resize(number_of_questions,-1);
            }
            break;

            case open_answer: // ���� ������ ��������� ����
            {
                getline(ss, temp_string);
                buf.variants[0].condition = QString::fromStdString(temp_string).toLower();
                answers.open_answer.resize(number_of_questions,"");
            }
            break;
        }
        test_questions.push_back(buf); // ������� ������ � ������
    }
}

/** ******************************************************************************* **/
// �������� ������� ������������
int Exam::check(vector<bool> &correct)
{
    int num_of_correct = 0;  // ���-�� ���������� �������

    for (size_t i = 0; i < number_of_questions; ++i)
    {
        int answer_num;
        QString answer_str;

        switch (test_questions[i].type)
        {
            case closed_answer: // ���� ������ ��������� ����
            {
                answer_num = answers.cb_answer[i];
                if (test_questions[i].variants[size_t(answer_num)].correctness) // ���� ����� ����������...
                {
                    ++num_of_correct;  //... ��������� ���������� ���������� �������
                    correct[i] = true; // ������� �
                }
            }
            break;

            case open_answer:   // ���� ������ ��������� ����
            {
                answer_str = answers.open_answer[i];
                if (test_questions[i].variants[0].condition == answer_str)
                {
                    ++num_of_correct;
                    correct[i] = true;
                }
            }
            break;
        }
    }
    return num_of_correct;
}

/** ******************************************************************************* **/
void Exam::display_result()
{
    // ������ ��������� ���������� ��������
    vector<bool> correct(number_of_questions, false);

    // ��������� ������ ������������
    int right_answers = check(correct);

    // ������� �������, ��� ���� �������� ������
    for(size_t i = 0; i < number_of_questions; ++i)
    {
        if(!correct[i])
        {
            ui->listWidget->addItem(test_questions[i].text);
        }
    }

    // ��������� ���������� ���������� ������� � ������� ������
    int result_percent = double(right_answers) / number_of_questions * 100;

    if (result_percent >= 80)
    {
        ui->Mark_2->setText("5");
    }
    else if (result_percent >= 70)
    {
        ui->Mark_2->setText("4");
    }
    else if (result_percent >= 50)
    {
        ui->Mark_2->setText("3");
    }
    else
    {
        ui->Mark_2->setText("2");
    }
}

/** ******************************************************************************* **/
// ������ ���� �� �������� ����
void Exam::on_beginTest_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->exam);
    begin_test(); // �������, ����������� ������������
}

/** ******************************************************************************* **/
// ��������� �� �������� ����
void Exam::on_backToMenu_clicked()
{
    emit back_toMenu();
}

/** ******************************************************************************* **/
// ��������� � ���� ������������
void Exam::on_backToMenu_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}

/** ******************************************************************************* **/
// ��������� ������������
void Exam::on_conclude_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->result);
    display_result();
}

/** ******************************************************************************* **/
// � �������� �������
void Exam::on_previous_clicked()
{
    if (step > 0)
    {
        --step;
        display_question();
    }
}

/** ******************************************************************************* **/
// � ���������� �������
void Exam::on_next_clicked()
{
    ++step;
    if (step <= size_t(number_of_questions-1))
    {
        display_question();    // ���� �� ��������� ������, �������� ������
    }
    else if(step > size_t(number_of_questions-1))
    {
        on_conclude_clicked(); // ��������� ������, ������� � �����������
    }
}

/** ******************************************************************************* **/
// ������� � ���� ������������ �� ���� �����������
void Exam::on_backToMenu_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}

/** ******************************************************************************* **/
// ���� ������� ���������� ��������
void Exam::on_numOfQuest_valueChanged(int arg1)
{
    number_of_questions = arg1;
}

/** ******************************************************************************* **/
// ��� ������ ������ �����
void Exam::on_choice1_clicked()
{
     answers.cb_answer[step] = 0;
}

/** ******************************************************************************* **/
// ��� ������ ������ �����
void Exam::on_choice2_clicked()
{
    answers.cb_answer[step] = 1;
}

/** ******************************************************************************* **/
// ��� ������ ������ �����
void Exam::on_choice3_clicked()
{
    answers.cb_answer[step] = 2;
}

/** ******************************************************************************* **/
// ��� ����� ����� � �������� �������
void Exam::on_answerOpen_textEdited(const QString &arg1)
{
    answers.open_answer[step] = arg1.toLower();
}
