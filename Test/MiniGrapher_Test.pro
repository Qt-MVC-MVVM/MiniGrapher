#-------------------------------------------------
#
# Project created by QtCreator 2018-07-15T10:49:07
#
#-------------------------------------------------

QT +=  testlib
QT += core
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniGrapher_Test
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

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
        ../ViewModel/viewmodel.cpp \
        ../Model/model.cpp \
        ../ViewModel/sinks/viewmodelsink.cpp \
        ../Lib/qcustomplot.cpp \
        ../Algorithm/lexer.cpp \
        ../Algorithm/prefixtree.cpp \
        ../ViewModel/commands/calculuscommand.cpp \
        ../ViewModel/commands/PaintCommand.cpp \
        MiniGrapher_Test.cpp

HEADERS += \
        ../Common/etlbase.h \
        ../ViewModel/viewmodel.h \
        ../Model/model.h \
        ../ViewModel/sinks/viewmodelsink.h \
        ../Lib/qcustomplot.h \
        ../Algorithm/lexer.h \
        ../Algorithm/prefixtree.h \
        ../ViewModel/commands/calculuscommand.h \
        ../ViewModel/commands/PaintCommand.h
