QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += core xml

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/ItemEditVisitor.cpp \
    src/ItemInfoVisitor.cpp \
    src/JsonManager.cpp \
    src/Library.cpp \
    src/LibraryFilterModel.cpp \
    src/LibraryModel.cpp \
    src/MainWindow.cpp \
    src/AbstractItem.cpp \
    src/Art.cpp \
    src/Book.cpp \
    src/DigitalItem.cpp \
    src/Movie.cpp \
    src/NewArtForm.cpp \
    src/NewItemDialog.cpp \
    src/PhysicalItem.cpp \
    src/Series.cpp \
    src/Video.cpp \
    src/Videogame.cpp \
    src/XmlManager.cpp \
    src/main.cpp

HEADERS += \
    headers/ItemEditVisitor.h \
    headers/ItemInfoVisitor.h \
    headers/ItemVisitor.h \
    headers/JsonManager.h \
    headers/Library.h \
    headers/LibraryFilterModel.h \
    headers/LibraryModel.h \
    headers/MainWindow.h \
    headers/AbstractItem.h \
    headers/Art.h \
    headers/Book.h \
    headers/DigitalItem.h \
    headers/Movie.h \
    headers/NewArtForm.h \
    headers/NewItemDialog.h \
    headers/NewItemForm.h \
    headers/PhysicalItem.h \
    headers/Series.h \
    headers/Video.h \
    headers/Videogame.h \
    headers/XmlManager.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    PaoLibrary.pro.user
