#ifndef MAINWINDOWPROSINK_H
#define MAINWINDOWPROSINK_H

#include "../../Common/etlbase.h"

class MainWindow;
class mainWindowProSink: public IPropertyNotification
{
public:
    mainWindowProSink(MainWindow *ptr);
    virtual void OnPropertyChanged(const std::string& str);
private:
    MainWindow *ptr_MainWindow;
};

#endif // MAINWINDOWPROSINK_H
