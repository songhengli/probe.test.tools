QT       += core gui charts sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    test_charts.cpp \
    test_dev.cpp \
    test_env.cpp \
    test_item.cpp \
    test_item_data.cpp \
    test_type.cpp

HEADERS += \
    mainwindow.h \
    test_charts.h \
    test_dev.h \
    test_env.h \
    test_item.h \
    test_item_data.h \
    test_type.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
