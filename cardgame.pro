#-------------------------------------------------
#
# Project created by QtCreator 2017-09-15T18:27:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGame
TEMPLATE = app


SOURCES += main.cpp\
        mymainwidget.cpp \
    fightwidget.cpp \
    fightscene.cpp \
    kernel.cpp \
    animation.cpp \
    mystackedwidget.cpp \
    card.cpp \
    deck.cpp \
    unithoveredevent.cpp \
    data.cpp \
    cardmoveevent.cpp \
    cardplayevent.cpp \
    unitold.cpp \
    unit.cpp

HEADERS  += mymainwidget.h \
    fightwidget.h \
    fightscene.h \
    kernel.h \
    animation.h \
    mystackedwidget.h \
    card.h \
    deck.h \
    unithoveredevent.h \
    data.h \
    cardmoveevent.h \
    cardplayevent.h \
    unitold.h \
    unit.h

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    README.md \
    IMAGES/ScreenFight.jpeg \
    IMAGES/ScreenMain.jpeg



RESOURCES += \
    fields.qrc \
    borders.qrc \
    cards.qrc \
    boy.qrc \
    zomby4.qrc


