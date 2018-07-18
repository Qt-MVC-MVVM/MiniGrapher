#include "startcommand.h"
#include "../app.h"

startCommand::startCommand(App *ptr_App)
{
    this->ptr_App = ptr_App;
}

startCommand::~startCommand()
{
}

void startCommand::SetParameter(const int &param)
{
}

void startCommand::Exec()
{
    ptr_App->initWindow.close();
    ptr_App->mainWindow.show();
}
