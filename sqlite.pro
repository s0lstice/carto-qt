# Add more folders to ship with the application, here
folder_01.source = qml/sqlite
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE1603E2B

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    database.cpp \
    data_points.cpp \
    data_heures.cpp \
    data_categories.cpp \
    data_gui.cpp \
    heure.cpp \
    data_jours.cpp \
    edit_point_gui.cpp \
    edite_categories.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()
 QT           += sql

HEADERS += \
    database.h \
    POI.h \
    data_heures.h \
    data_categories.h \
    data_gui.h \
    data_points.h \
    heure.h \
    data_jours.h \
    edit_point_gui.h \
    edite_categories.h

TRANSLATIONS += lan_fr

FORMS += \
    edition_point.ui
