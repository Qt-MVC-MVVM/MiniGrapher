#include "initial.h"
#include "ui_initial.h"

Initial::Initial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Initial)
{
    ui->setupUi(this);
    connect(ui->QuitButton, SIGNAL(clicked(bool)), this, SLOT(Quit()));
    connect(ui->StartButton, SIGNAL(clicked(bool)), this, SLOT(Start()));
    this->show();
}

Initial::~Initial()
{
    delete ui;
}

void Initial::Start()
{
    this->hide();
    /*
    window = new QMainWindow;
    widget = new MainWidget;
    window->setCentralWidget(widget);
    window->resize(900, 600);
    window->show();
    */
    window = new MainWindow;
    window->show();
}

void Initial::Quit()
{
    this->close();
}
