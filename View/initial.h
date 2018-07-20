#ifndef INITIAL_H
#define INITIAL_H

#include <QWidget>
#include <QMovie>
#include "mainwindow.h"
#include "../Common/etlbase.h"
namespace Ui {
class Initial;
}

class Initial : public QWidget
{
    Q_OBJECT

public:
    explicit Initial(QWidget *parent = 0);
    ~Initial();
    void set_start_command(std::shared_ptr<ICommandBase> start_command);

protected slots:
    void on_StartButton_clicked();
    void on_QuitButton_clicked();

private:
    Ui::Initial *ui;
    std::shared_ptr<ICommandBase> startCommand;
};

#endif // INITIAL_H
