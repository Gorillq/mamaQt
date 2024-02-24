TEMPLATE = app
CONFIG += windows
SOURCES += main.cpp
HEADERS += baza.h
QT += widgets
win32 {
    # add Windows application icon, not applicable to unix/macx platform
    RC_ICONS += icon.ico
}

