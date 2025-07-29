QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src\AbstractItem.cpp \
    src\Art.cpp \
    src\Book.cpp \
    src\DigitalItem.cpp \
    src\Movie.cpp \
    src\PhysicalItem.cpp \
    src\Series.cpp \
    src\Video.cpp \
    src\Videogame.cpp \
    src\main.cpp \
    src\mainwindow.cpp

HEADERS += \
    headers\AbstractItem.h \
    headers\Art.h \
    headers\Book.h \
    headers\DigitalItem.h \
    headers\Movie.h \
    headers\PhysicalItem.h \
    headers\Series.h \
    headers\Video.h \
    headers\Videogame.h \
    headers\library.h \
    headers\mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    PaoLibrary.pro.user
