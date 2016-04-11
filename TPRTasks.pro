#-------------------------------------------------
#
# Project created by QtCreator 2016-04-03T20:26:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TPRTasks
TEMPLATE = app


SOURCES += main.cpp\
        titlewidget.cpp \
    qcustomplot.cpp \
    Kuvshinov/Nuclear.cpp \
    Martinov/Task_1_4_1.cpp \
    Maslov/Z1/Invest_z1.cpp \
    Maslov/Z1/answer1.cpp \
    Maslov/Z1/alternative1.cpp \
    Maslov/Z2/alternative2.cpp \
    Maslov/Z2/answer2.cpp \
    Maslov/Z2/Invest_z2.cpp

HEADERS  += titlewidget.h \
    qcustomplot.h \
    Kuvshinov/Nuclear.h \
    Martinov/Task_1_4_1.h \
    Maslov/Z1/Invest_z1.h \
    Maslov/Z1/answer1.h \
    Maslov/Z1/alternative1.h \
    Maslov/Z2/alternative2.h \
    Maslov/Z2/answer2.h \
    Maslov/Z2/Invest_z2.h

FORMS += \
    Maslov/Z1/Invest_z1.ui \
    Maslov/Z2/Invest_z2.ui
