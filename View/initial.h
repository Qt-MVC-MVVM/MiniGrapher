#ifndef INITIAL_H
#define INITIAL_H

#include <QWidget>
#include <QMovie>
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
    void Init();
};

#endif // INITIAL_H
