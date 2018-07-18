#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include "../Common/etlbase.h"
#include "sinks/mainwindowprosink.h"
#include "sinks/mainwindowsetsink.h"
=======
#include <QtWidgets/QPushButton>

>>>>>>> 6d79f588d1ec13cbef3532f3aec32730157c67e3
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand);
    std::shared_ptr<IPropertyNotification> getPtrWindowProSink(void);
    std::shared_ptr<ICommandNotification> getPtrWindowSetSink(void);
private:
    Ui::MainWindow *ui;
    std::shared_ptr<mainWindowProSink> _ptrWindowProSink;
    std::shared_ptr<mainWindowSetSink> _ptrWindowSetSink;
    std::shared_ptr<ICommandBase> _ptrCommand;
};

#endif // MAINWINDOW_H
