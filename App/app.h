#ifndef APP_H
#define APP_H

#include "../View/mainwindow.h"
#include "../View/initial.h"
#include "../Model/model.h"
#include "../ViewModel/viewmodel.h"
#include "commands/startcommand.h"


class App
{
public:
    App();
    ~App();
    Initial initWindow;
    MainWindow mainWindow;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;
    std::shared_ptr<startCommand> ptr_startCommand;
    void run();
};

#endif // APP_H
