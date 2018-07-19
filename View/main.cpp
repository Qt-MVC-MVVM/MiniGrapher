#include "initial.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    Initial init;
    init.show();

    return a.exec();
}
