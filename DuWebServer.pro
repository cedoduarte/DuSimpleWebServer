#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T08:28:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuWebServer
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DuWebServer.cpp

HEADERS  += Widget.h \
    DuWebServer.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14

DISTFILES += \
    index.html

RESOURCES += \
    res.qrc
