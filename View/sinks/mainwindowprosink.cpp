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
}

