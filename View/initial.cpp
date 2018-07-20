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

void Initial::set_start_command(std::shared_ptr<ICommandBase> start_command)
{
    startCommand = start_command;
}
void Initial::on_StartButton_clicked()
{
    startCommand->Exec();
}

void Initial::on_QuitButton_clicked()
{
    qApp->exit(0);
}
