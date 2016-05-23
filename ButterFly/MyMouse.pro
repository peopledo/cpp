#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T11:38:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyMouse
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mylabel.cpp

HEADERS  += mywidget.h \
    mylabel.h

FORMS    += mywidget.ui

CONFIG += C++11

RESOURCES += \
    img.qrc
