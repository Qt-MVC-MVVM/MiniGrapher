#include "initial.h"
#include "ui_initial.h"

Initial::Initial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Initial)
{
    ui->setupUi(this);
}

Initial::~Initial()
{
    delete ui;
}

void Initial::set_ptrCommand(std::shared_ptr<ICommandBase> ptrCommand)
{
    _ptrCommand = ptrCommand;
}
void Initial::on_StartButton_clicked()
{
    _ptrCommand->Exec();
}

void Initial::on_QuitButton_clicked()
{
    qApp->exit(0);
}
