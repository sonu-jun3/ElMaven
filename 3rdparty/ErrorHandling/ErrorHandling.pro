TEMPLATE = lib

DESTDIR=$$top_builddir/libs/
OBJECTS_DIR=$$top_builddir/tmp/error_handling
MOC_DIR=$$top_builddir/tmp/error_handling

CONFIG += staticlib

INCLUDEPATH += $$top_srcdir/3rdparty/Logger

LIBS += -lLogger

SOURCES += MavenException.cpp errorcodes.cpp
HEADERS += MavenException.h errorcodes.h