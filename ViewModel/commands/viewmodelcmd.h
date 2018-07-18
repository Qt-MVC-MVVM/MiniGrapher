#ifndef VIEWMODELCMD_H
#define VIEWMODELCMD_H

#include "../../Common/etlbase.h"

class ViewModel;
class ViewModelCmd: public ICommandBase
{
public:
    ViewModelCmd(ViewModel *ptr_ViewModel);
    virtual void SetParameter(const int &param);
    virtual void Exec();

private:
    ViewModel *ptr_ViewModel;
};

#endif // VIEWMODELCMD_H
