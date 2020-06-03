/********************************************************************************
** Form generated from reading UI file 'exam.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM_H
#define UI_EXAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_Exam
{
public:
    ClickableLabel *goMenu;
    QStackedWidget *stackedWidget;
    QWidget *instructionPage;
    QWidget *testPage;
    QWidget *result;

    void setupUi(QWidget *Exam)
    {
        if (Exam->objectName().isEmpty())
            Exam->setObjectName(QString::fromUtf8("Exam"));
        Exam->resize(1000, 900);
        goMenu = new ClickableLabel(Exam);
        goMenu->setObjectName(QString::fromUtf8("goMenu"));
        goMenu->setGeometry(QRect(340, 810, 321, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito"));
        font.setPointSize(28);
        goMenu->setFont(font);
        stackedWidget = new QStackedWidget(Exam);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1011, 791));
        instructionPage = new QWidget();
        instructionPage->setObjectName(QString::fromUtf8("instructionPage"));
        stackedWidget->addWidget(instructionPage);
        testPage = new QWidget();
        testPage->setObjectName(QString::fromUtf8("testPage"));
        stackedWidget->addWidget(testPage);
        result = new QWidget();
        result->setObjectName(QString::fromUtf8("result"));
        stackedWidget->addWidget(result);

        retranslateUi(Exam);

        QMetaObject::connectSlotsByName(Exam);
    } // setupUi

    void retranslateUi(QWidget *Exam)
    {
        Exam->setWindowTitle(QCoreApplication::translate("Exam", "Form", nullptr));
        goMenu->setText(QCoreApplication::translate("Exam", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exam: public Ui_Exam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM_H
