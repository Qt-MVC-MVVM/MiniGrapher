#ifndef SUBMITCOMMAND_H
#define SUBMITCOMMAND_H

#include "../../Common/etlbase.h"

class ViewModel;
class SubmitCommand
{
public:
    SubmitCommand(ViewModel *ptr_ViewModel);
    virtual void SetParameter(const int& param);
    virtual void Exec();
private:
    ViewModel *ptr_ViewModel;
};

#endif // SUBMITCOMMAND_H
