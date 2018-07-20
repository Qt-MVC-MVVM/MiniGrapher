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

    mainWindow.set_paint_command(viewmodel->getPaintCmd());
    mainWindow.set_differential_command(viewmodel->getDifferentialCmd());
    mainWindow.set_integral_command(viewmodel->getIntegralCmd());
    mainWindow.set_x(viewmodel->getX());
    mainWindow.set_y(viewmodel->getY());
    mainWindow.setDifferential(viewmodel->getDifferential());
    mainWindow.setIntegral(viewmodel->getIntegral());

    viewmodel->AddPropertyNotification(mainWindow.getPtrWindowProSink());
    viewmodel->AddCommandNotification(mainWindow.getPtrWindowSetSink());

    ptr_startCommand = std::make_shared<startCommand>(this);

    initWindow.set_start_command(std::static_pointer_cast<ICommandBase>(this->ptr_startCommand));
    initWindow.show();
}
