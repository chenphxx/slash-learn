QT += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    code_highlighter.cpp \
    git.cpp \
    main.cpp \
    mainwindow.cpp \
    new_data_dialog.cpp \
    new_table.cpp \
    query_execute.cpp

HEADERS += \
    code_highlighter.h \
    git.h \
    mainwindow.h \
    new_data_dialog.h \
    new_table.h \
    query_execute.h \
    resource.h

FORMS += \
    git.ui \
    mainwindow.ui \
    new_data_dialog.ui \
    new_table.ui \
    query_execute.ui

RC_ICONS = sources/icon/code_database.ico  # 添加logo

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
