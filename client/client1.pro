QT += quick

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        src/cpp/chatclient.cpp \
        src/cpp/chatmodel.cpp \
        src/cpp/chatworker.cpp

RESOURCES += qml.qrc
INCLUDEPATH += $$PWD/src/headers/
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:{
LIBS += -lsetupapi
LIBS += -lwsock32
LIBS += -lws2_32
DEFINES += _WIN32_WINNT=0x0501
}

win32:{
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_atomic-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_chrono-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_container-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_context-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_contract-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_coroutine-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_date_time-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_fiber-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_filesystem-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_iostreams-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_system-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_locale-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_thread-mgw73-mt-d-x64-1_72.dll
LIBS += -L$$PWD/../../../boost_1_72_0/boost_mingw_730_64/lib/ -llibboost_timer-mgw73-mt-d-x64-1_72.dll
}

INCLUDEPATH += $$PWD/../../../boost_1_72_0/boost_mingw_730_64/include/boost-1_72
DEPENDPATH += $$PWD/../../../boost_1_72_0/boost_mingw_730_64/include/boost-1_72

HEADERS += \
    src/headers/chatclient.h \
    src/headers/chatmodel.h \
    src/headers/chatworker.h \
    src/headers/packet.h
