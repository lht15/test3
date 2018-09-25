#-------------------------------------------------
#
# Project created by QtCreator 2018-07-19T15:02:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test3
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
        main.cpp \
        mainwindow.cpp \
    toolbox.cpp \
    doc.cpp \
    dialog.cpp \
    doc_longterm.cpp \
    taskitem.cpp \
    hard_constraint.cpp \
    output.cpp \
    dep_item.cpp \
    output.cpp \
    dialog_dep.cpp

HEADERS += \
        mainwindow.h \
    toolbox.h \
    doc.h \
    dialog.h \
    doc_longterm.h \
    taskitem.h \
    hard_constraint.h \
    output.h \
    dep_item.h \
    output.h \
    dialog_dep.h

FORMS += \
        mainwindow.ui \
    toolbox.ui \
    dialog.ui \
    output.ui \
    output.ui \
    dialog_dep.ui
CONFIG += qaxcontainer
