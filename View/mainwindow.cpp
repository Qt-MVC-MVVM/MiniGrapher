#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "d2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
<<<<<<< HEAD
   _ptrWindowProSink= std::make_shared<mainWindowProSink>(mainWindowProSink(this));
   _ptrWindowSetSink=std::make_shared<mainWindowSetSink>(mainWindowSetSink(this));
=======
   D2 w;
   w.resize(720, 480);
   w.show();
>>>>>>> 6d79f588d1ec13cbef3532f3aec32730157c67e3
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand)
{
    _ptrCommand = ptrCommand;
}

std::shared_ptr<IPropertyNotification> MainWindow::getPtrWindowProSink()
{
    return std::static_pointer_cast<IPropertyNotification>(_ptrWindowProSink);
}

std::shared_ptr<ICommandNotification> MainWindow::getPtrWindowSetSink()
{
    return std::static_pointer_cast<ICommandNotification>(_ptrWindowSetSink);
}
