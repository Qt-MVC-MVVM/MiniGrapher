#ifndef INITIAL_H
#define INITIAL_H

#include <QWidget>
#include <QMovie>
#include <QtWidgets/QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Initial;
}

class Initial : public QWidget
{
    Q_OBJECT

public:
    explicit Initial(QWidget *parent = 0);
    ~Initial();

protected slots:
    void Start();
    void Quit();

private:
    Ui::Initial *ui;
    MainWindow *window;
};

#endif // INITIAL_H
