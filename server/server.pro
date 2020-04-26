TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        src/cpp/chatroom.cpp \
        src/cpp/chatserver.cpp \
        src/cpp/chatsession.cpp

HEADERS += \
    src/header/chatparticipant.h \
    src/header/chatroom.h \
    src/header/chatserver.h \
    src/header/chatsession.h \
    src/header/packet.h

INCLUDEPATH += $$PWD/src/header/

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
