#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T16:54:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app

FORMS = \
    mainwindow \
    AddItem.ui

SOURCES += \
main.cpp \
    MainWindow.cpp \
    AddItem.cpp \
    dataaccess.cpp

HEADERS += \
    MainWindow.h \
    AddItem.h \
    dataaccess.h



