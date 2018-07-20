#include "submitcommand.h"

SubmitCommand::SubmitCommand(ViewModel *ptr_ViewModel)
{
    this->ptr_ViewModel = ptr_ViewModel;
}

void SubmitCommand::SetParameter(const int &param)
{

}

void SubmitCommand::Exec()
{
    ptr_ViewModel->execSubmitCmd();
    ptr_ViewModel->Fire_OnCommandComplete("SubmitCmd", true);
}

