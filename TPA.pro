#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T10:50:23
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TPA
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    sign_up.cpp \
    sign_in.cpp \
    home_screen.cpp \
    managepsw.cpp \
    searchpwd.cpp \
    modify.cpp \
    stdafx.cpp \
    md5.cpp \
    aes.cpp \
    base64.cpp

HEADERS  += mainwindow.h \
    sign_up.h \
    sign_in.h \
    home_screen.h \
    managepsw.h \
    json.hpp \
    modify.h \
    searchpwd.h \
    stdafx.h \
    md5.h \
    aes.h \
    base64.h

FORMS    += mainwindow.ui \
    sign_up.ui \
    sign_in.ui \
    home_screen.ui \
    managepsw.ui \
    searchpwd.ui \
    modify.ui

RESOURCES += \
    rs.qrc
