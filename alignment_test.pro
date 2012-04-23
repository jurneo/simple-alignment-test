#-------------------------------------------------
#
# Project created by QtCreator 2012-04-23T10:20:15
#
#-------------------------------------------------

QT       += core
QT       -= gui
TARGET = alignment_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    alignment.cpp

INCLUDEPATH += $$quote($$(sisworkspace))/libraries/eigen/include/eigen3

HEADERS += \
    alignment.h \
    alignmentmodel.h \
    point2d.h
