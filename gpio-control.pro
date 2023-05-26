######################################################################
# Automatically generated by qmake (3.1) Sun Jul 11 11:08:07 2021
######################################################################

TEMPLATE = app
TARGET = gpio-control
QT += widgets core
QMAKE_CXXFLAGS += -std=c++0x
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += src/GPIO.h src/ToggleButton.h src/Ui.h src/WindowGpioControl.h src/WindowMorse.h
SOURCES += src/GPIO.cpp src/main.cpp

# Output directory
DESTDIR = build

# Object files directory
OBJECTS_DIR = build/.obj

# MOC output directory
MOC_DIR = build/.moc

# UI output directory
UI_DIR = build/.ui

# RCC output directory
RCC_DIR = build/.rcc

# Create the build directories
QMAKE_EXTRA_TARGETS += build_dirs
build_dirs.target = $$DESTDIR $$OBJECTS_DIR $$MOC_DIR $$UI_DIR $$RCC_DIR
# build_dirs.commands = mkdir -p $$QMAKE_EXTRA_TARGETS
build_dirs.commands = mkdir -p $$DESTDIR $$OBJECTS_DIR $$MOC_DIR $$UI_DIR $$RCC_DIR



# Run the build_dirs target before building
QMAKE_EXTRA_TARGETS += pre_build
pre_build.depends = build_dirs

# Make sure the build_dirs target is executed before the actual build starts
PRE_TARGETDEPS += pre_build
