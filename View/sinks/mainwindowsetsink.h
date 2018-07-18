#ifndef MAINWINDOWSETSINK_H
#define MAINWINDOWSETSINK_H

#include "../../Common/etlbase.h"

class MainWindow;
class mainWindowSetSink: public ICommandNotification
{
public:
    mainWindowSetSink(MainWindow *ptr);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
    MainWindow *ptr_MainWindow;
};

#endif // MAINWINDOWSETSINK_H
