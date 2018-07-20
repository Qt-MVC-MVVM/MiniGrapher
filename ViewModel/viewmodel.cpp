#include "viewmodel.h"
#include "sinks/viewmodelsink.h"
#include "commands/PaintCommand.h"

ViewModel::ViewModel()
{
    ptr_ViewModelSink = std::make_shared<ViewModelSink>(this);
    ptr_DifferentialCmd = std::make_shared<DifferentialCommand>(this);
    ptr_IntegralCmd = std::make_shared<IntegralCommand>(this);
    ptr_PaintCmd = std::make_shared<PaintCommand>(this);
}

ViewModel::~ViewModel()
{
}

void ViewModel::setModel(std::shared_ptr<Model> ptr_Model)
{
    this->ptr_Model = ptr_Model;
    this->ptr_Model->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(ptr_ViewModelSink));
}

std::shared_ptr<ICommandBase> ViewModel::getDifferentialCmd()
{
    return std::static_pointer_cast<ICommandBase>(ptr_DifferentialCmd);
}

std::shared_ptr<ICommandBase> ViewModel::getIntegralCmd()
{
    return std::static_pointer_cast<ICommandBase>(ptr_IntegralCmd);
}

std::shared_ptr<ICommandBase> ViewModel::getPaintCmd()
{
    return std::static_pointer_cast<ICommandBase>(ptr_PaintCmd);
}

void ViewModel::Exec_differential_command(const std::string &str, const double &x)
{
    if(str!=ptr_Model->getString())ptr_Model->buildtree(str);
    ptr_Model->differential(x);
}

void ViewModel::Exec_integral_command(const std::string &str, const double &left, const double &right)
{
    if(str!=ptr_Model->getString())ptr_Model->buildtree(str);
    ptr_Model->integral(left,right);
}

void ViewModel::Exec_paint_command(const std::string &str, const double &left, const double &right)
{
    if(str!=ptr_Model->getString())ptr_Model->buildtree(str);
    ptr_Model->cal(left,right);
}

std::shared_ptr<QVector<double>> ViewModel::getX()
{
    return ptr_Model->getX();
}

std::shared_ptr<QVector<double>> ViewModel::getY()
{
    return ptr_Model->getY();
}
