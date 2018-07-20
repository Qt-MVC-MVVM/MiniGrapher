#include "PaintCommand.h"
#include "../viewmodel.h"

PaintCommand::PaintCommand(ViewModel *ptr_ViewModel)
{
    this->ptr_ViewModel = ptr_ViewModel;
    // For testing purpose
    this->LowerBound = -100;
    this->UpperBound = 100;
    this->str = "x^2+2*x+1";

}

void PaintCommand::SetParameter(const string &param,const double &param1,const double &param2)
{
    UpperBound=param2;
    LowerBound=param1;
    str=param;
}

void PaintCommand::Exec()
{
    ptr_ViewModel -> Exec_paint_command(str,LowerBound,UpperBound);
    ptr_ViewModel -> Fire_OnCommandComplete("PaintCommand",true);
}
