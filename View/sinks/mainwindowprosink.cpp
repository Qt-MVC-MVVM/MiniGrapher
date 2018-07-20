#include "mainwindowprosink.h"
#include "../mainwindow.h"

mainWindowProSink::mainWindowProSink(MainWindow *ptr)
{
    ptr_MainWindow = ptr;
}

void mainWindowProSink::OnPropertyChanged(const std::string &str)
{
    if(str == "Lexer")
    {
        ptr_MainWindow->plotGraph();
    }
    else if(str == "Differential")
    {
        ptr_MainWindow->showDifferential();
        ptr_MainWindow->update();
    }
    else if(str == "Integral")
    {
        ptr_MainWindow->showIntegral();
        ptr_MainWindow->update();
    }
}

