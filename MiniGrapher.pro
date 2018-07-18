#-------------------------------------------------
#
# Project created by QtCreator 2018-07-15T10:49:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniGrapher
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
<<<<<<< HEAD:MiniGrapher.pro
        App/main.cpp \
        View/mainwindow.cpp \
    	View/initial.cpp \
    View/sinks/mainwindowprosink.cpp \
    View/sinks/mainwindowsetsink.cpp \
    App/app.cpp \
    App/commands/startcommand.cpp \
    ViewModel/viewmodel.cpp \
    Model/model.cpp \
    ViewModel/sinks/viewmodelsink.cpp \
    ViewModel/commands/viewmodelcmd.cpp

HEADERS += \
        View/mainwindow.h \
    	View/initial.h \
    View/sinks/mainwindowprosink.h \
    View/sinks/mainwindowsetsink.h \
    Common/etlbase.h \
    App/app.h \
    App/commands/startcommand.h \
    ViewModel/viewmodel.h \
    Model/model.h \
    ViewModel/sinks/viewmodelsink.h \
    ViewModel/commands/viewmodelcmd.h

FORMS += \
        View/mainwindow.ui \
    	View/initial.ui
=======
        main.cpp \
        mainwindow.cpp \
        initial.cpp \
        d2.cpp

HEADERS += \
        mainwindow.h \
        initial.h \
        d2.h

FORMS += \
        mainwindow.ui \
        initial.ui
>>>>>>> 6d79f588d1ec13cbef3532f3aec32730157c67e3:View/MiniGrapher.pro