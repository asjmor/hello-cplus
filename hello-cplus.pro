TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    patest.c \
    threadlocktest.cpp

HEADERS += \
    patest.h \
    threadlocktest.h
