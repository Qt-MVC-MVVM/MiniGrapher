#ifndef CALCULUSCOMMAND_H
#define CALCULUSCOMMAND_H

#include "../../Common/etlbase.h"

class ViewModel;

class IntegralCommand: public ICommandBase
{
public:
    IntegralCommand(ViewModel *ptr_ViewModel);
    virtual void SetParameter(const std::string &param,const double &param1,const double &param2);
    virtual void Exec();

private:
    ViewModel *ptr_ViewModel;
    double Upperbound,LowerBound;
    std::string str;
};

class DifferentialCommand: public ICommandBase
{
public:
    DifferentialCommand(ViewModel *ptr_ViewModel);
    virtual void SetParameter(const std::string &param,const double &param1);
    virtual void Exec();

private:
    ViewModel *ptr_ViewModel;
    double x;
    std::string str;
};

#endif // CALCULUSCOMMAND_H
