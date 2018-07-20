#ifndef CALCULUSCOMMAND_H
#define CALCULUSCOMMAND_H

#include "../../Common/etlbase.h"
#include <string>

using std::string;

class ViewModel;

class IntegralCommand: public ICommandBase
{
public:
    IntegralCommand(ViewModel *ptr_ViewModel);
    virtual void SetParameter(const string &param,const double &param1){}
    virtual void SetParameter(const string &param,const double &param1,const double &param2);
    virtual void Exec();

private:
    ViewModel *ptr_ViewModel;
    double UpperBound,LowerBound;
    string str;
};

class DifferentialCommand: public ICommandBase
{
public:
    DifferentialCommand(ViewModel *ptr_ViewModel);
    virtual void SetParameter(const string &param,const double &param1);
    virtual void SetParameter(const string &param,const double &param1,const double &param2){}
    virtual void Exec();

private:
    ViewModel *ptr_ViewModel;
    double x;
    string str;
};

#endif // CALCULUSCOMMAND_H
