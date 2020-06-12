#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QtSvg>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color:white;");
    w.show();

    return a.exec();
}
