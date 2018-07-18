#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../Model/model.h"
#include "../Common/etlbase.h"
#include "sinks/viewmodelsink.h"
#include "commands/viewmodelcmd.h"

class ViewModel: public Proxy_PropertyNotification<ViewModel>, public Proxy_CommandNotification<ViewModel>
{
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> ptr_Model);
    std::shared_ptr<ICommandBase> getLayoutCmd();
    void execViewModelCmd();

private:
    std::shared_ptr<Model> ptr_Model;
    std::shared_ptr<ViewModelSink> ptr_ViewModelSink;
    std::shared_ptr<ViewModelCmd> ptr_ViewModelCmd;
};

#endif // VIEWMODEL_H
