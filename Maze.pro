TEMPLATE = app
CONFIG -= console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_MAC_SDK = macosx10.13

SOURCES += main.cpp \
    mazegame.cpp \
    playerstate.cpp

#LIBS += -L"/Users/steve.tyler/DEV/SFML/SFML-2.4.2-osx/lib"
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

HEADERS += \
    mazegame.h \
    playerstate.h \
    resourceholder.h
