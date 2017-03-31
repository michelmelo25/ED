TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    listas/slist.cpp \
    listas/dlist.cpp \
    listas/rslist.cpp

HEADERS += \
    listas/slist.h \
    listas/dlist.h \
    listas/rslist.h \
    listas/snode.h

