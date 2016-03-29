TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    SerialPort.cpp \
	protocol.cpp

HEADERS += \
    SerialPort.h \
	protocol.h
