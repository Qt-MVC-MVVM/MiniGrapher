#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "d2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   D2 w;
   w.resize(720, 480);
   w.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
