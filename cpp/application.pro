QT += widgets
QT += core

RESOURCES = application.qrc

DESTDIR = ../python3/

HEADERS =   src/headers/mainWindow.h \
            src/headers/pane.h \
            src/headers/timePane.h \
            src/headers/weatherStatPane.h \
            src/headers/styleReader.h \
            src/headers/styleMap.h

SOURCES =   src/main.cpp \
            src/mainWindow.cpp \
            src/pane.cpp \
            src/timePane.cpp \
            src/weatherStatPane.cpp \
            src/styleReader.cpp \
            src/styleMap.cpp