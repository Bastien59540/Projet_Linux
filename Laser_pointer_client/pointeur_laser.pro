QT += widgets serialport

TARGET = Pointeur_laser
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    custom_scene.cpp \
    protocol.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    custom_scene.h \
    protocol.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    ressources.qrc
