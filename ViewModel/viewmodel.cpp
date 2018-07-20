#include "viewmodel.h"
#include "sinks/viewmodelsink.h"
#include "commands/submitcommand.h"

ViewModel::ViewModel()
{
    ptr_ViewModelSink = std::make_shared<ViewModelSink>(this);
    ptr_SubmitCmd  = std::make_shared<SubmitCommand>(this);
}

ViewModel::~ViewModel()
{

}

void ViewModel::setModel(std::shared_ptr<Model> ptr_Model)
{
    this->ptr_Model = ptr_Model;
    this->ptr_Model->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(ptr_ViewModelSink));
}

std::shared_ptr<ICommandBase> ViewModel::getSubmitCmd()
{
    return std::static_pointer_cast<ICommandBase>(ptr_SubmitCmd);
}

void ViewModel::execSubmitCmd()
{
    //ptr_Model->Dosth
}

