#include "calculuscommand.h"
#include "../viewmodel.h"

IntegralCommand::IntegralCommand(ViewModel *ptr_ViewModel)
{
    this->ptr_ViewModel = ptr_ViewModel;
}

void IntegralCommand::SetParameter(const std::string &param,const double &param1,const double &param2)
{
    str = param;
    Upperbound = param2;
    LowerBound = param1;
}

void IntegralCommand::Exec()
{
//    ptr_ViewModel -> Exec_integral_command();
//    ptr_ViewModel -> Fire_OnCommandComplete("IntegralCommand",true);
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
//    ptr_ViewModel -> Exec_differential_command();
//    ptr_ViewModel -> Fire_OnCommandComplete("DifferentialCommand",true);
}
