TEMPLATE = app
CONFIG -= console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += static
CONFIG += copy_dir_files

macx {
    QMAKE_MAC_SDK = macosx10.13
}

SOURCES += main.cpp \
    mazegame.cpp \
    playerstate.cpp \
    gameentity.cpp \
    scenenode.cpp \
    player.cpp \
    mazeworld.cpp

win32 {
    LIBS += -L"C:/Users/tyler/DEV/SFML-2.4.2/lib"
    CONFIG(release, debug|release): LIBS += -lsfml-main -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
    CONFIG(debug, debug|release): LIBS += -lsfml-main-d -lsfml-audio-d -lsfml-graphics-d -lsfml-system-d -lsfml-network-d -lsfml-window-d
    INCLUDEPATH += "$$PWD/../SFML-2.4.2/include/"
    DEPENDPATH += "$$PWD/../SFML-2.4.2/include/"
}

macos {
    LIBS += -L"/usr/local/lib"
    CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
    CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
    INCLUDEPATH += "/usr/local/include"
    DEPENDPATH += "/usr/local/include"
}





HEADERS += \
    mazegame.h \
    playerstate.h \
    resourceholder.h \
    gameentity.h \
    scenenode.h \
    player.h \
    textures.h \
    mazeworld.h
