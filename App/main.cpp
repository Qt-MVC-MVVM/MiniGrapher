#include "app.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App MiniGrapher;
    MiniGrapher.run();

    return a.exec();
}
