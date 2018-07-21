#include "mainwindowsetsink.h"
#include "../mainwindow.h"

mainWindowSetSink::mainWindowSetSink(MainWindow *ptr)
{
    ptr_MainWindow = ptr;
}

void mainWindowSetSink::OnCommandComplete(const std::string &str, bool bOK)
{
    if(str == "PaintCommand")
    {
        if(bOK)
        {
            ptr_MainWindow->showPaintSucceed();
        }
        else
        {
            ptr_MainWindow->showPaintFailed();
        }
    }
}
