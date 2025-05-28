#-------------------------------------------------
#
# Project created by QtCreator 2023-02-14T15:53:56
#
#-------------------------------------------------

QT += xml
QT += core gui sql
QT       += widgets

TARGET = KFVerifier
TEMPLATE = lib

DEFINES += KFVERIFIER_LIBRARY

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
        kfverifier.cpp \
    mainwidget.cpp \
    verifier.cpp \
    windowres.cpp \
    test_kf.cpp

HEADERS += \
        kfverifier.h \
        kfverifier_global.h \ 
    mainwidget.h \
    verifier.h \
    windowres.h \
    test_kf.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH +=  ../../../src ../../../lib/src ../../../lib/src/libxml2/include ../../../lib/src/libiconv/include

LIBS += -L$$OUT_PWD/../ATProject/ -lATProject

LIBS += -L$$OUT_PWD/../ATGUI/ -lATGUI

LIBS += -L$$OUT_PWD/../ATCore/ -lATCore

LIBS += -L$$OUT_PWD/../libxml2/ -lxml2

LIBS += -L$$OUT_PWD/../libiconv/ -liconv

LIBS += -L$$OUT_PWD/../KnowledgeField/ -lKnowledgeField

FORMS += \
    mainwidget.ui \
    windowres.ui

