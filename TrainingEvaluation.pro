QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customtreewidget.cpp \
    directorytree.cpp \
    main.cpp \
    mainwindow.cpp \
    mediadropwidget.cpp \
    projectdatamanager.cpp

HEADERS += \
    customtreewidget.h \
    directorytree.h \
    json.hpp \
    mainwindow.h \
    mediadropwidget.h \
    projectdatamanager.h

FORMS += \
    mainwindow.ui

msvc::QMAKE_CXXFLAGS +=-utf-8


#MSVC{
#    QMAKE_CFLAGS += /utf-8
#    QMAKE_CXXFLAGS += /utf-8
#}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc








