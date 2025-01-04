#include "mainwindow.h"

#include <QApplication>

#include "linklist.h"
#include "userinterface.h"

int main(int argc, char   *argv[])
{
    QApplication a(argc, argv);
    UserInterface w;
    w.show();
    return a.exec();


    return 0;

}
