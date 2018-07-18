#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   _ptrWindowProSink= std::make_shared<mainWindowProSink>(mainWindowProSink(this));
   _ptrWindowSetSink=std::make_shared<mainWindowSetSink>(mainWindowSetSink(this));
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
