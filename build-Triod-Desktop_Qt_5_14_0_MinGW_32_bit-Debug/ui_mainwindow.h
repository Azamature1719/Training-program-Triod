/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>
#include <demonstration.h>
#include <exam.h>
#include <theory.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    ClickableLabel *goTheory;
    ClickableLabel *goDemo;
    ClickableLabel *goExam;
    Theory *theoryPage;
    Demonstration *demoPage;
    Exam *examPage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 10, 1000, 900));
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        widget = new QWidget(mainPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 280, 861, 591));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        goTheory = new ClickableLabel(widget);
        goTheory->setObjectName(QString::fromUtf8("goTheory"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito"));
        font.setPointSize(28);
        goTheory->setFont(font);
        goTheory->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(goTheory);

        goDemo = new ClickableLabel(widget);
        goDemo->setObjectName(QString::fromUtf8("goDemo"));
        goDemo->setFont(font);
        goDemo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(goDemo);

        goExam = new ClickableLabel(widget);
        goExam->setObjectName(QString::fromUtf8("goExam"));
        goExam->setFont(font);
        goExam->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(goExam);

        stackedWidget->addWidget(mainPage);
        theoryPage = new Theory();
        theoryPage->setObjectName(QString::fromUtf8("theoryPage"));
        stackedWidget->addWidget(theoryPage);
        demoPage = new Demonstration();
        demoPage->setObjectName(QString::fromUtf8("demoPage"));
        stackedWidget->addWidget(demoPage);
        examPage = new Exam();
        examPage->setObjectName(QString::fromUtf8("examPage"));
        stackedWidget->addWidget(examPage);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        goTheory->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\276\321\200\320\270\321\217", nullptr));
        goDemo->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\272\321\202\320\270\320\272\321\203\320\274", nullptr));
        goExam->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\267\320\275\320\260\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
