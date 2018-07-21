#include "calculuscommand.h"
#include "../viewmodel.h"

IntegralCommand::IntegralCommand(ViewModel *ptr_ViewModel)
{
    this->ptr_ViewModel = ptr_ViewModel;
}

void IntegralCommand::SetParameter(const std::string &param,const double &param1,const double &param2)
{
    UpperBound=param2;
    LowerBound=param1;
    str=param;
}

void IntegralCommand::Exec()
{
    ptr_ViewModel -> CalcIntegral(str,LowerBound,UpperBound);
    ptr_ViewModel -> Fire_OnCommandComplete("IntegralCommand",true);
}

DifferentialCommand::DifferentialCommand(ViewModel *ptr_ViewModel)
{
    this->ptr_ViewModel = ptr_ViewModel;
}

void DifferentialCommand::SetParameter(const std::string &param, const double &param1)
{
    str = param;
    x = param1;
}

void DifferentialCommand::Exec()
{
    ptr_ViewModel -> CalcDifferential(str,x);
    ptr_ViewModel -> Fire_OnCommandComplete("DifferentialCommand",true);
}
