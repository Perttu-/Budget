#-------------------------------------------------
#
# Project created by QtCreator 2016-08-28T16:10:35
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Budjetti
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    databaseinterface.cpp

HEADERS  += mainwindow.h \
    databaseinterface.h

FORMS    += mainwindow.ui
