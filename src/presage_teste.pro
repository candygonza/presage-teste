PRESAGE_ROOT = $$(PRESAGE_ROOT)
isEmpty(PRESAGE_ROOT) {
        win32 {
                error(Environment variable PRESAGE_ROOT must be set)
        }
        unix {
                PRESAGE_ROOT = /usr
        }
}
! exists($${PRESAGE_ROOT}) {
        error(PRESAGE_ROOT does not exist. Please set environment variable PRESAGE_ROOT to a valid presage installation.)
}

QT += gui widgets qml

CONFIG += c++11 console
#CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


unix:!macx: LIBS += -lpresage -L/usr/lib -L/usr/bin
INCLUDEPATH   = $${PRESAGE_ROOT}/include/x86_64-linux-gnu/qt5 \
                /usr/local/include/ \
                /usr/include/ \
                /usr/bin
