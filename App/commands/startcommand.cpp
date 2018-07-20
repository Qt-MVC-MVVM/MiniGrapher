#include "startcommand.h"
#include "../app.h"

startCommand::startCommand(App *ptr_App)
{
    this->ptr_App = ptr_App;
}

startCommand::~startCommand()
{
}

void startCommand::SetParameter(const std::string &param,const double &param1,const double &param2)
{
}

void startCommand::Exec()
{
    ptr_App->initWindow.close();
    ptr_App->mainWindow.show();
}
