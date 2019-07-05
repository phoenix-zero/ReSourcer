TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += \
        argumentParser.cpp \
        fileparsers.cpp \
        main.cpp

LIBS += -lboost_program_options

HEADERS += \
        parser.hpp
