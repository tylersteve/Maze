TEMPLATE = app
CONFIG -= console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mazegame.cpp \
    playerstate.cpp

LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

CONFIG += c++11

HEADERS += \
    mazegame.h \
    playerstate.h
