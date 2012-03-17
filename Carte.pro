#-------------------------------------------------
#
# Project created by QtCreator 2012-02-07T17:15:04
#
#-------------------------------------------------
include(QMapControl/QMapControl.pri)

QT       += core gui network

TARGET = Carte

TEMPLATE = app




SOURCES += main.cpp\
        carte.cpp \
    askdatabase.cpp \
    heure.cpp \
    data_points.cpp \
    data_jours.cpp \
    data_heures.cpp \
    data_categories.cpp \
    database.cpp \
    montrerpoint.cpp

HEADERS  += carte.h \
    POI.h \
    askdatabase.h \
    database.h \
    heure.h \
    database.h \
    data_points.h \
    data_jours.h \
    data_heures.h \
    data_categories.h \
    montrerpoint.h



FORMS    += carte.ui \
    askdatabase.ui \
    montrerpoint.ui

QT += xml
