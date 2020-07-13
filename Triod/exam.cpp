#include <string>
#include <sstream>
#include <ctime>
#include <QMessageBox>
#include <QRegExpValidator>
#include <random>
#include <fstream>
#include <QTimer>
#include "exam.h"
#include "ui_exam.h"

using namespace std;

Exam::Exam(QWidget *parent) :
    QWidget(parent), ui(new Ui::Exam)
{
    ui->setupUi(this);
    number_of_questions = 5;         // Количество вопросов - 5
    ui->numOfQuest->setRange(5, 15); // В spinbox установить мин и макс значения ввода
    questionnaire = read_testFile("Files/questions.txt"); // Считать в одну строку все вопросы

    QRegExp re("^[0-9]{1,}[.]{1}[0-9]{1,}$");
    QRegExpValidator *validator = new QRegExpValidator(re, this);
    ui->answerOpen->setValidator(validator);
}

Exam::~Exam()
{
    delete ui;
}

/** ******************************************************************************* **/
// Считать файл с вопросами
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
// Начать выполнение тестирования
void Exam::begin_test()
{
    time_t seed = time(nullptr);
    mt19937 mt(seed);

    // Очистить все поля, которые заполняются во время прохождения теста
    test_questions.clear();
    answers.cb_answer.clear();
    answers.open_answer.clear();
    ui->listWidget->clear();
    step = 0;

    // Создать вопрос
    make_question();

    // Перемещать все вопросы
    shuffle(test_questions.begin(),test_questions.end(),mt);

    // Проверить вопросы на наличие вопросы с открытым ответом
    for (question &quest : test_questions)
    {
        // Если вопрос закрытого типа, перемешать варианты ответов
        if (quest.type == closed_answer)
        {
            shuffle(quest.variants.begin(),quest.variants.end()-1,mt);
        }
    }

    // Вывести вопрос на экран
    display_question();
}

/** ******************************************************************************* **/
// Вывод вопроса на экран
void Exam::display_question()
{
    ui->textQuestiom->setText(test_questions[step].text);

    switch (test_questions[step].type)
    {
        case closed_answer:
        {
            test_questions[step].variants[0].condition.push_front(' ');
            test_questions[step].variants[1].condition.push_front(' ');
            test_questions[step].variants[2].condition.push_front(' ');

            ui->QuestionTypes->setCurrentWidget(ui->close);
            ui->answer1T->setText(test_questions[step].variants[0].condition);
            ui->answer2T->setText(test_questions[step].variants[1].condition);
            ui->answer3T->setText(test_questions[step].variants[2].condition);

            ui->choice1->setAutoExclusive(false);
            ui->choice1->setChecked(false);
            ui->choice1->setAutoExclusive(true);

            ui->choice2->setAutoExclusive(false);
            ui->choice2->setChecked(false);
            ui->choice2->setAutoExclusive(true);

            ui->choice3->setAutoExclusive(false);
            ui->choice3->setChecked(false);
            ui->choice3->setAutoExclusive(true);
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
// Функйия составления вопроса
void Exam::make_question()
{
    string temp_string; // Текущая строка
    question buf;       // Буферный вопрос

    stringstream ss(questionnaire);
    while (getline(ss, temp_string))
    {
        buf.type = temp_string[1] - '0'; // Считать тип вопроса
        buf.text = QString::fromStdString({temp_string.begin()+2, temp_string.end()});

        switch (buf.type) // Перейти к соответствующему блоку в зависимости от типа вопроса
        {
            case closed_answer: // Если вопрос закрытого типа
            {
                buf.variants[0].correctness = true; // Первый ответ всегда верный
                for (size_t i=0; i < 3; ++i) // Считать три варианта ответа на вопрос
                {
                    getline(ss, temp_string);
                    buf.variants[i].condition = QString::fromStdString(temp_string);
                }
                answers.cb_answer.resize(number_of_questions, 3);
            }
            break;

            case open_answer: // Если вопрос открытого типа
            {
                getline(ss, temp_string);
                buf.variants[0].condition = QString::fromStdString(temp_string).toLower();
                answers.open_answer.resize(number_of_questions,"");
            }
            break;
        }
        test_questions.push_back(buf); // Занести вопрос в вектор
    }
}

/** ******************************************************************************* **/
// Проверка ответов пользователя
int Exam::check(vector<bool> &correct)
{
    int num_of_correct = 0;  // Кол-во правильных ответов

    for (size_t i = 0; i < number_of_questions; ++i)
    {
        int answer_num;
        QString answer_str;

        switch (test_questions[i].type)
        {
            case closed_answer: // Если вопрос закрытого типа
            {
                answer_num = answers.cb_answer[i];
                if (test_questions[i].variants[size_t(answer_num)].correctness) // Если ответ правильный...
                {
                    ++num_of_correct;  // Увеличить количество правильных ответов
                    correct[i] = true; // Занести в
                }
            }
            break;

            case open_answer:   // Если вопрос открытого типа
            {
                answer_str = answers.open_answer[i];

                qDebug() << answer_str << test_questions[i].variants[0].condition;
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
    // Вектор правильно отвеченных вопросов
    vector<bool> correct(number_of_questions, false);

    // Проверить ответы пользователя
    int right_answers = check(correct);

    if(!ui->listWidget->count())
    {
        // Вывести вопросы, где были допущены ошибки
        for(size_t i = 0; i < number_of_questions; ++i)
        {
            if(!correct[i])
            {
                ui->listWidget->addItem(test_questions[i].text);
            }
        }
    }

    // Посчитать количество правильных ответов и вывести оценку
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
// Начать тест из главного окна
void Exam::on_beginTest_clicked()
{
    ui->beginTest->startTransitTitles();
    QTimer *timer = new QTimer;
    timer->singleShot(500, this, SLOT(beginGO()));
}


void Exam::beginGO()
{
    ui->stackedWidget->setCurrentWidget(ui->exam);
    begin_test(); // Функция, запускающая тестирование
}

/** ******************************************************************************* **/
// Вернуться из главного меню
void Exam::on_backToMenu_clicked()
{
    ui->backToMenu->startTransitTitles();
    QTimer *timer = new QTimer;
    timer->singleShot(500, this, SIGNAL(back_toMenu()));
}

/** ******************************************************************************* **/
// Вернуться в меню тестирование
void Exam::on_backToMenu_2_clicked()
{
    ui->backToMenu_2->startTransitTitles();
    QTimer *timer = new QTimer;
    timer->singleShot(500, this, SLOT(menuGO()));
}

/** ******************************************************************************* **/
// Заверщить тестирование
void Exam::on_conclude_clicked()
{
    ui->conclude->startTransitTitles();
    QTimer *timer = new QTimer;
    timer->singleShot(500, this, SLOT(concludeGO()));
}

void Exam::concludeGO()
{
    ui->stackedWidget->setCurrentWidget(ui->result);
    display_result();
}

/** ******************************************************************************* **/
// К прошлому вопросу
void Exam::on_previous_clicked()
{
    ui->previous->startTransitTitles();

    if (step > 0)
    {
        --step;
        display_question();
    }
}

/** ******************************************************************************* **/
// К следующему вопросу
void Exam::on_next_clicked()
{
    ++step;

    if (step <= size_t(number_of_questions-1))
    {
        ui->next->startTransitTitles();
        display_question();    // Если не последний вопрос, показать вопрос
    }
    else if(step > size_t(number_of_questions-1))
    {
        on_conclude_clicked(); // Последний вопрос, перейти к результатам
    }
}

/** ******************************************************************************* **/
// Переход в меню тестирования из поля результатов
void Exam::on_backToMenu_4_clicked()
{
    ui->backToMenu_4->startTransitTitles();
    QTimer *timer = new QTimer;
    timer->singleShot(500, this, SLOT(menuGO()));
}

void Exam::menuGO()
{
    ui->stackedWidget->setCurrentWidget(ui->mainMenu);
}

/** ******************************************************************************* **/
// Было выбрано количество вопросов
void Exam::on_numOfQuest_valueChanged(int arg1)
{
    number_of_questions = arg1;
}

/** ******************************************************************************* **/
// Был выбран первый ответ
void Exam::on_choice1_clicked()
{
     answers.cb_answer[step] = 0;
}

/** ******************************************************************************* **/
// Был выбран второй ответ
void Exam::on_choice2_clicked()
{
    answers.cb_answer[step] = 1;
}

/** ******************************************************************************* **/
// Был выбран третий ответ
void Exam::on_choice3_clicked()
{
    answers.cb_answer[step] = 2;
}

/** ******************************************************************************* **/
// Был внесён ответ в открытом вопросе
void Exam::on_answerOpen_textEdited(const QString &arg1)
{
    answers.open_answer[step] = arg1.toLower();
}
