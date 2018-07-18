#include "viewmodel.h"
#include "sinks/viewmodelsink.h"
#include "commands/viewmodelcmd.h"

ViewModel::ViewModel()
{
    ptr_ViewModelSink = std::make_shared<ViewModelSink>(this);
    ptr_ViewModelCmd  = std::make_shared<ViewModelCmd>(this);
}

ViewModel::~ViewModel()
{

}

void ViewModel::setModel(std::shared_ptr<Model> ptr_Model)
{
    this->ptr_Model = ptr_Model;
    this->ptr_Model->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(ptr_ViewModelSink));
}

std::shared_ptr<ICommandBase> ViewModel::getLayoutCmd()
{
    return std::static_pointer_cast<ICommandBase>(ptr_ViewModelCmd);
}

void ViewModel::execViewModelCmd()
{

}

