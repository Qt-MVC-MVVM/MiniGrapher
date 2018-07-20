#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../Model/model.h"
#include "../Common/etlbase.h"
#include "sinks/viewmodelsink.h"
#include "commands/PaintCommand.h"
#include "commands/calculuscommand.h"

class ViewModel:public Proxy_PropertyNotification<ViewModel>,
        public Proxy_CommandNotification<ViewModel>
{
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> ptr_Model);
    std::shared_ptr<ICommandBase> getPaintCmd();
    std::shared_ptr<ICommandBase> getDifferentialCmd();
    std::shared_ptr<ICommandBase> getIntegralCmd();
    void Exec_differential_command(const std::string &str,const double &x);
    void Exec_integral_command(const std::string &str,const double &left,const double &right);
    void Exec_paint_command(const std::string &str,const double &left,const double &right);
    std::shared_ptr<QVector<double>> getX();
    std::shared_ptr<QVector<double>> getY();
    std::shared_ptr<double> getIntegral();
    std::shared_ptr<double> getDifferential();
private:
    std::shared_ptr<Model> ptr_Model;
    std::shared_ptr<ViewModelSink> ptr_ViewModelSink;
    std::shared_ptr<IntegralCommand> ptr_IntegralCmd;
    std::shared_ptr<DifferentialCommand> ptr_DifferentialCmd;
    std::shared_ptr<PaintCommand> ptr_PaintCmd;
};

#endif // VIEWMODEL_H
