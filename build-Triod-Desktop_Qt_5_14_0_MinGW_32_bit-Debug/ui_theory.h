/********************************************************************************
** Form generated from reading UI file 'theory.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEORY_H
#define UI_THEORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_Theory
{
public:
    ClickableLabel *goMenu;

    void setupUi(QWidget *Theory)
    {
        if (Theory->objectName().isEmpty())
            Theory->setObjectName(QString::fromUtf8("Theory"));
        Theory->resize(1000, 900);
        goMenu = new ClickableLabel(Theory);
        goMenu->setObjectName(QString::fromUtf8("goMenu"));
        goMenu->setGeometry(QRect(90, 70, 321, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito"));
        font.setPointSize(28);
        goMenu->setFont(font);

        retranslateUi(Theory);

        QMetaObject::connectSlotsByName(Theory);
    } // setupUi

    void retranslateUi(QWidget *Theory)
    {
        Theory->setWindowTitle(QCoreApplication::translate("Theory", "Form", nullptr));
        goMenu->setText(QCoreApplication::translate("Theory", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Theory: public Ui_Theory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEORY_H
