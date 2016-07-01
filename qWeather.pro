#-------------------------------------------------
#
# Project created by QtCreator 2016-06-28T14:27:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qWeather
TEMPLATE = app


SOURCES += src\main.cpp\
        src\mainpage.cpp \
    src\dailywidget.cpp \
    src\horizonalslider.cpp \
    src\titlewidget.cpp

HEADERS  += src\mainpage.h \
    src\dailywidget.h \
    src\horizonalslider.h \
    src\titlewidget.h

CONFIG   += c++11

RESOURCES += \
    cityList.qrc
