/********************************************************************************
** Form generated from reading UI file 'demonstration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMONSTRATION_H
#define UI_DEMONSTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_Demonstration
{
public:
    QStackedWidget *stackedWidget;
    QWidget *instruction;
    QWidget *processTriod;
    QLabel *label;
    ClickableLabel *goMenu;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QLabel *label_13;
    QSlider *horizontalSlider_3;
    QLineEdit *lineEdit_2;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_5;
    QLabel *label_16;
    QLineEdit *lineEdit_6;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *lineEdit_3;
    QLabel *label_22;
    QLineEdit *lineEdit_4;
    QLabel *label_23;
    QLineEdit *lineEdit_7;
    QLabel *label_24;
    QLabel *label_26;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_27;
    QLineEdit *lineEdit_11;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *lineEdit_12;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLineEdit *lineEdit_13;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_8;

    void setupUi(QWidget *Demonstration)
    {
        if (Demonstration->objectName().isEmpty())
            Demonstration->setObjectName(QString::fromUtf8("Demonstration"));
        Demonstration->resize(1000, 839);
        stackedWidget = new QStackedWidget(Demonstration);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -170, 1001, 1011));
        instruction = new QWidget();
        instruction->setObjectName(QString::fromUtf8("instruction"));
        stackedWidget->addWidget(instruction);
        processTriod = new QWidget();
        processTriod->setObjectName(QString::fromUtf8("processTriod"));
        label = new QLabel(processTriod);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 616, 25, 43));
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(26);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        goMenu = new ClickableLabel(processTriod);
        goMenu->setObjectName(QString::fromUtf8("goMenu"));
        goMenu->setGeometry(QRect(330, 920, 351, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(28);
        goMenu->setFont(font1);
        label_2 = new QLabel(processTriod);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 691, 26, 43));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(processTriod);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(21, 760, 26, 43));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(processTriod);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 830, 16, 43));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(processTriod);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(523, 620, 31, 43));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(processTriod);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(530, 720, 23, 43));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(processTriod);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 850, 16, 26));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Verdana"));
        font2.setPointSize(16);
        label_9->setFont(font2);
        label_9->setTextFormat(Qt::AutoText);
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(processTriod);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 780, 16, 26));
        label_10->setFont(font2);
        label_10->setTextFormat(Qt::AutoText);
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(processTriod);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 710, 16, 26));
        label_11->setFont(font2);
        label_11->setTextFormat(Qt::AutoText);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(processTriod);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(50, 640, 16, 26));
        label_12->setFont(font2);
        label_12->setTextFormat(Qt::AutoText);
        label_12->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(processTriod);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(90, 650, 271, 21));
        horizontalSlider->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalSlider->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(processTriod);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(380, 610, 51, 51));
        label_13 = new QLabel(processTriod);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(90, 610, 291, 31));
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalSlider_3 = new QSlider(processTriod);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(90, 730, 271, 21));
        horizontalSlider_3->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        lineEdit_2 = new QLineEdit(processTriod);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(380, 690, 51, 51));
        label_14 = new QLabel(processTriod);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(90, 690, 201, 31));
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_15 = new QLabel(processTriod);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(90, 770, 251, 31));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_5 = new QLineEdit(processTriod);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(380, 760, 51, 51));
        label_16 = new QLabel(processTriod);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(90, 840, 251, 31));
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_6 = new QLineEdit(processTriod);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(380, 830, 51, 51));
        label_19 = new QLabel(processTriod);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(560, 820, 21, 31));
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_20 = new QLabel(processTriod);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(560, 730, 21, 31));
        label_20->setFont(font2);
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_21 = new QLabel(processTriod);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(560, 630, 21, 31));
        label_21->setFont(font2);
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_3 = new QLineEdit(processTriod);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(600, 600, 51, 41));
        label_22 = new QLabel(processTriod);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(590, 630, 101, 20));
        label_22->setFont(font2);
        label_22->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        lineEdit_4 = new QLineEdit(processTriod);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(600, 660, 51, 41));
        label_23 = new QLabel(processTriod);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(700, 630, 21, 31));
        label_23->setFont(font2);
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_7 = new QLineEdit(processTriod);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(730, 620, 51, 51));
        label_24 = new QLabel(processTriod);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(790, 630, 51, 20));
        label_24->setFont(font2);
        label_24->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_26 = new QLabel(processTriod);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(700, 820, 21, 31));
        label_26->setFont(font2);
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_8 = new QLineEdit(processTriod);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(600, 790, 51, 41));
        lineEdit_9 = new QLineEdit(processTriod);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(600, 850, 51, 41));
        lineEdit_10 = new QLineEdit(processTriod);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(730, 810, 51, 51));
        label_27 = new QLabel(processTriod);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(590, 820, 101, 20));
        label_27->setFont(font2);
        label_27->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        lineEdit_11 = new QLineEdit(processTriod);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(600, 720, 51, 41));
        label_29 = new QLabel(processTriod);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(650, 720, 61, 41));
        label_29->setFont(font2);
        label_29->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(processTriod);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(710, 730, 20, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Verdana"));
        font3.setPointSize(48);
        font3.setBold(true);
        font3.setWeight(75);
        label_30->setFont(font3);
        label_30->setAlignment(Qt::AlignCenter);
        lineEdit_12 = new QLineEdit(processTriod);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(740, 720, 51, 41));
        label_31 = new QLabel(processTriod);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(800, 720, 51, 20));
        label_31->setFont(font2);
        label_31->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_32 = new QLabel(processTriod);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(800, 700, 51, 31));
        label_32->setFont(font2);
        label_32->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_33 = new QLabel(processTriod);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(800, 740, 51, 31));
        label_33->setFont(font2);
        label_33->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_34 = new QLabel(processTriod);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(860, 720, 21, 31));
        label_34->setFont(font2);
        label_34->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_13 = new QLineEdit(processTriod);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(890, 710, 51, 51));
        label_35 = new QLabel(processTriod);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(650, 790, 31, 41));
        label_35->setFont(font2);
        label_35->setAlignment(Qt::AlignCenter);
        label_36 = new QLabel(processTriod);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(660, 850, 31, 41));
        label_36->setFont(font2);
        label_36->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(processTriod);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(790, 820, 51, 31));
        label_37->setFont(font2);
        label_37->setAlignment(Qt::AlignCenter);
        label_38 = new QLabel(processTriod);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(650, 600, 51, 31));
        label_38->setFont(font2);
        label_38->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_39 = new QLabel(processTriod);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(650, 660, 31, 31));
        label_39->setFont(font2);
        label_39->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_40 = new QLabel(processTriod);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(800, 650, 31, 31));
        label_40->setFont(font2);
        label_40->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_41 = new QLabel(processTriod);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(790, 610, 51, 31));
        label_41->setFont(font2);
        label_41->setAlignment(Qt::AlignCenter);
        label_42 = new QLabel(processTriod);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(430, 610, 61, 51));
        label_42->setFont(font2);
        label_42->setAlignment(Qt::AlignCenter);
        label_43 = new QLabel(processTriod);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(430, 700, 31, 31));
        label_43->setFont(font2);
        label_43->setAlignment(Qt::AlignCenter);
        label_44 = new QLabel(processTriod);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(430, 770, 31, 31));
        label_44->setFont(font2);
        label_44->setAlignment(Qt::AlignCenter);
        label_45 = new QLabel(processTriod);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(430, 840, 51, 31));
        label_45->setFont(font2);
        label_45->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(processTriod);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(524, 810, 31, 51));
        label_8->setFont(font);
        label_8->setTextFormat(Qt::AutoText);
        label_8->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(processTriod);

        retranslateUi(Demonstration);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Demonstration);
    } // setupUi

    void retranslateUi(QWidget *Demonstration)
    {
        Demonstration->setWindowTitle(QCoreApplication::translate("Demonstration", "Form", nullptr));
        label->setText(QCoreApplication::translate("Demonstration", "R", nullptr));
        goMenu->setText(QCoreApplication::translate("Demonstration", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\274\320\265\320\275\321\216", nullptr));
        label_2->setText(QCoreApplication::translate("Demonstration", "U", nullptr));
        label_3->setText(QCoreApplication::translate("Demonstration", "U", nullptr));
        label_4->setText(QCoreApplication::translate("Demonstration", "I", nullptr));
        label_5->setText(QCoreApplication::translate("Demonstration", "S", nullptr));
        label_6->setText(QCoreApplication::translate("Demonstration", "\316\274", nullptr));
        label_9->setText(QCoreApplication::translate("Demonstration", "A", nullptr));
        label_10->setText(QCoreApplication::translate("Demonstration", "C", nullptr));
        label_11->setText(QCoreApplication::translate("Demonstration", "A", nullptr));
        label_12->setText(QCoreApplication::translate("Demonstration", "C", nullptr));
        label_13->setText(QCoreApplication::translate("Demonstration", "\320\241\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\260 \321\201\320\265\321\202\320\272\320\265", nullptr));
        label_14->setText(QCoreApplication::translate("Demonstration", "\320\235\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265 \321\206\320\265\320\277\320\270", nullptr));
        label_15->setText(QCoreApplication::translate("Demonstration", "\320\235\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265 \320\275\320\260 \321\201\320\265\321\202\320\272\320\265", nullptr));
        label_16->setText(QCoreApplication::translate("Demonstration", "\320\241\320\270\320\273\320\260 \320\260\320\275\320\276\320\264\320\275\320\276\320\263\320\276 \321\202\320\276\320\272\320\260", nullptr));
        label_19->setText(QCoreApplication::translate("Demonstration", "=", nullptr));
        label_20->setText(QCoreApplication::translate("Demonstration", "=", nullptr));
        label_21->setText(QCoreApplication::translate("Demonstration", "=", nullptr));
        label_22->setText(QCoreApplication::translate("Demonstration", "________________________", nullptr));
        label_23->setText(QCoreApplication::translate("Demonstration", "=", nullptr));
        label_24->setText(QCoreApplication::translate("Demonstration", "________________________", nullptr));
        label_26->setText(QCoreApplication::translate("Demonstration", "=", nullptr));
        label_27->setText(QCoreApplication::translate("Demonstration", "________________________", nullptr));
        label_29->setText(QCoreApplication::translate("Demonstration", "\320\272\320\236\320\274", nullptr));
        label_30->setText(QCoreApplication::translate("Demonstration", "\342\213\205", nullptr));
        label_31->setText(QCoreApplication::translate("Demonstration", "________________________", nullptr));
        label_32->setText(QCoreApplication::translate("Demonstration", "\320\274\320\220", nullptr));
        label_33->setText(QCoreApplication::translate("Demonstration", "\320\222", nullptr));
        label_34->setText(QCoreApplication::translate("Demonstration", "=", nullptr));
        label_35->setText(QCoreApplication::translate("Demonstration", "\320\222", nullptr));
        label_36->setText(QCoreApplication::translate("Demonstration", "\320\274\320\220", nullptr));
        label_37->setText(QCoreApplication::translate("Demonstration", "\320\272\320\236\320\274", nullptr));
        label_38->setText(QCoreApplication::translate("Demonstration", "\320\274\320\220", nullptr));
        label_39->setText(QCoreApplication::translate("Demonstration", "\320\222", nullptr));
        label_40->setText(QCoreApplication::translate("Demonstration", "\320\222", nullptr));
        label_41->setText(QCoreApplication::translate("Demonstration", "\320\274\320\220", nullptr));
        label_42->setText(QCoreApplication::translate("Demonstration", "\320\272\320\236\320\274", nullptr));
        label_43->setText(QCoreApplication::translate("Demonstration", "\320\222", nullptr));
        label_44->setText(QCoreApplication::translate("Demonstration", "\320\222", nullptr));
        label_45->setText(QCoreApplication::translate("Demonstration", "\320\274\320\220", nullptr));
        label_8->setText(QCoreApplication::translate("Demonstration", "R", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Demonstration: public Ui_Demonstration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMONSTRATION_H
