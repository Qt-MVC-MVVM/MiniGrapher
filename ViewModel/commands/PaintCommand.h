#ifndef VIEWMODELCMD_H
#define VIEWMODELCMD_H
#include <string>
#include "../../Common/etlbase.h"

using std::string;

class ViewModel;

class PaintCommand: public ICommandBase
{
public:
    PaintCommand(ViewModel *ptr_ViewModel);
    virtual void SetParameter(const string &param,const double &param1){}
    virtual void SetParameter(const string &param,const double &param1,const double &param2);
    virtual void Exec();

private:
    ViewModel *ptr_ViewModel;
    double UpperBound,LowerBound;
    string str;
};

#endif // VIEWMODELCMD_H
