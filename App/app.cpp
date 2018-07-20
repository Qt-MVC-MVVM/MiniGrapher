#include "app.h"

App::App()
{
}

App::~App()
{
}

void App::run()
{
    model = std::make_shared<Model>();
    viewmodel = std::make_shared<ViewModel>();
    viewmodel->setModel(model);

    mainWindow.set_submit_command(viewmodel->getSubmitCmd());

    viewmodel->AddPropertyNotification(mainWindow.getPtrWindowProSink());
    viewmodel->AddCommandNotification(mainWindow.getPtrWindowSetSink());

    ptr_startCommand = std::make_shared<startCommand>(this);

    initWindow.set_start_command(std::static_pointer_cast<ICommandBase>(this->ptr_startCommand));
    initWindow.show();
}
