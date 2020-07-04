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

    // Тип вопроса
    static const int closed_answer = 1, open_answer = 2;

    // Структура ответа теста
    struct answer
    {
        QString condition;        // Текст ответа
        bool correctness = false; // Правильность ответа
    };

    // Структура ответа на вопрос (зависит от типа вопроса)
    struct answer_types
    {
        std::vector<int> cb_answer;       // Закрытый вопрос
        std::vector<QString> open_answer; // Открытый вопрос
    };

    // Структура вопроса теста
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
    void back_toMenu(); // Вернуться в главное меню

public:
    explicit Exam(QWidget *parent = nullptr);
    ~Exam();

    void display_question(); // Вывод вопроса теста
    void display_result();   // Вывод результатов теста
    int check(std::vector<bool> &correct); // Функция проверки вопросов
    std::string read_testFile(const std::string &filename); // Функция, считывающая вопросы теста
    void begin_test();       // Функция, запускающая тестирование
    void make_question();    // Функция формирования вопроса

private slots:

    void on_beginTest_clicked();    // Начать тест
    void on_backToMenu_clicked();   // Вернуться в главное меню
    void on_backToMenu_2_clicked(); // Вернуться в меню тестирования из теста
    void on_backToMenu_4_clicked(); // Перейти в меню тестирования из окна результатов
    void on_conclude_clicked();     // Завершеить тестирование
    void on_previous_clicked();     // Перейти к предыдущему вопросу
    void on_next_clicked();         // Перейти к следующему вопросу
    void on_numOfQuest_valueChanged(int arg1);// Отследить изменение количества вопросов
    void on_choice1_clicked();      // Если был выбран первый ответ
    void on_choice2_clicked();      // Если был выбран второй ответ
    void on_choice3_clicked();      // Если был выбран третий ответ
    void on_answerOpen_textEdited(const QString &arg1);// Если был введён ответ на открытый вопрос

private:
    Ui::Exam *ui;
};

#endif // EXAM_H
