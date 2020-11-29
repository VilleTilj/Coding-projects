TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

SOURCES += \
    actor.cpp \
    actoritem.cpp \
    city.cpp \
    creategame.cpp \
    dialoggamesettings.cpp \
    gameengine.cpp \
    main.cc \
    mainwindow.cpp \
    nukeactor.cpp \
    playeractor.cpp \
    statistics.cpp \
    vehicle.cpp

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib


INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    dialoggamesettings.ui \
    mainwindow.ui

HEADERS += \
    actor.hh \
    actoritem.hh \
    city.hh \
    dialoggamesettings.hh \
    gameengine.hh \
    mainwindow.hh \
    nukeactor.hh \
    playeractor.hh \
    statistics.hh \
    vehicle.hh

RESOURCES += \
    Graphics.qrc \
    dataFiles.qrc \
    scores.csv

DISTFILES += \
    scores.csv

