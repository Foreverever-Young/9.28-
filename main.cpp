#include "MainWindow.h"
#include "Budget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Budget win;
    w.setWindowTitle("记账本");
    //w.resize(570,700);
    w.move(650,220);
    //w.show();


    return a.exec();
}
