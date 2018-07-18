#ifndef VIEWMODELSINK_H
#define VIEWMODELSINK_H

#include "../../Common/etlbase.h"

class ViewModel;
class ViewModelSink: public IPropertyNotification
{
public:
    ViewModelSink(ViewModel *ptr);
    virtual void OnPropertyChanged(const std::string& str);
private:
    ViewModel *ptr_ViewModel;
};

#endif // VIEWMODELSINK_H
