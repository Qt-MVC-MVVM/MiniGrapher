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
    void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand);

protected slots:
    void on_StartButton_clicked();
    void on_QuitButton_clicked();

private:
    Ui::Initial *ui;
    std::shared_ptr<ICommandBase> _ptrCommand;
};

#endif // INITIAL_H
