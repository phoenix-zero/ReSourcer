TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/local/include /usr/include

SOURCES += \
        argumentParser.cpp \
        fileparsers.cpp \
        main.cpp

LIBS += -lboost_program_options

HEADERS += \
        parser.hpp
