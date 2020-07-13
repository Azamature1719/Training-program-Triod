#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QtSvg>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    a.setWindowIcon(QIcon("Files/PNG/icon.png"));
    w.setWindowTitle("Учебная программа \"Триод\"");
    w.setStyleSheet("background-color:white;");
    w.show();

    return a.exec();
}
