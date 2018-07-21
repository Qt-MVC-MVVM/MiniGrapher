#include "PaintCommand.h"
#include "../viewmodel.h"

PaintCommand::PaintCommand(ViewModel *ptr_ViewModel)
{
    this->ptr_ViewModel = ptr_ViewModel;
}

void PaintCommand::SetParameter(const string &param,const double &param1,const double &param2)
{
    UpperBound=param2;
    LowerBound=param1;
    str=param;
}

void PaintCommand::Exec()
{
    if(ptr_ViewModel -> CalcCoordinate(str,LowerBound,UpperBound))
        ptr_ViewModel -> Fire_OnCommandComplete("PaintCommand",true);
    else ptr_ViewModel -> Fire_OnCommandComplete("PaintCommand",false);
}
