#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H
#include "../../Common/etlbase.h"

class App;
class startCommand: public ICommandBase
{
public:
    startCommand(App *ptr_App);
    ~startCommand();
    virtual void SetParameter(const std::string &param,const double &param1){}
    virtual void SetParameter(const std::string &param,const double &param1,const double &param2);
    virtual void Exec();
private:
    App *ptr_App;
};

#endif // STARTCOMMAND_H
