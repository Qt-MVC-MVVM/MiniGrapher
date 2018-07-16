#include "initial.h"
#include "ui_initial.h"

Initial::Initial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Initial)
{
    ui->setupUi(this);
    Init();
}

Initial::~Initial()
{
    delete ui;
}

void Initial::Init()
{
    this->show();
    connect(ui->QuitButton, SIGNAL(clicked(bool)), this, SLOT(Quit()));
    connect(ui->StartButton, SIGNAL(clicked(bool)), this, SLOT(Start()));
}

void Initial::Start()
{
    this->hide();
    window = new MainWindow;
    window->show();
}

void Initial::Quit()
{
    this->close();
}
