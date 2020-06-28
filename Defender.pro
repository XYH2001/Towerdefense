QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    enemy.cpp \
    gameworld.cpp \
    gameworld2.cpp \
    icon.cpp \
    lose.cpp \
    lose2.cpp \
    main.cpp \
    mainwindow.cpp \
    mw2.cpp \
    mw3.cpp \
    object.cpp \
    shooter.cpp \
    win.cpp \
    win2.cpp

HEADERS += \
    bullet.h \
    enemy.h \
    gameworld.h \
    gameworld2.h \
    icon.h \
    lose.h \
    lose2.h \
    mainwindow.h \
    mw2.h \
    mw3.h \
    object.h \
    shooter.h \
    win.h \
    win2.h

FORMS += \
    lose.ui \
    lose2.ui \
    mainwindow.ui \
    mw2.ui \
    mw3.ui \
    win.ui \
    win2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    game.qrc \
    game.qrc
