#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T16:54:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app

FORMS = \
    mainwindow \
    AddItem.ui

SOURCES += main.cpp \
    MainWindow.cpp \
    AddItem.cpp

HEADERS += \
    MainWindow.h \
    AddItem.h \
    dataaccess.h



