#include "mainwindow.h"
#include "initial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Initial w;
    w.show();

    return a.exec();
}
