QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battle_state.cpp \
    battlecry_state.cpp \
    human_factory.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    tavern_state.cpp \
    tawern_brawler.cpp

HEADERS += \
    battle_state.h \
    battlecry_state.h \
    factory.h \
    human_factory.h \
    mainwindow.h \
    player.h \
    state.h \
    tavern_state.h \
    tawern_brawler.h \
    warrior.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
