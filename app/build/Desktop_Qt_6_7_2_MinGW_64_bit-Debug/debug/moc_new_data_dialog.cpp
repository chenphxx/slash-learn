/****************************************************************************
** Meta object code from reading C++ file 'new_data_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../new_data_dialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_data_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSnew_data_dialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSnew_data_dialogENDCLASS = QtMocHelpers::stringData(
    "new_data_dialog",
    "on_new_data_save_clicked",
    "",
    "on_new_data_cancel_clicked",
    "on_language_switch_activated",
    "receive_table_name",
    "table_name",
    "init_table",
    "on_new_data_delete_clicked",
    "on_new_data_clear_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSnew_data_dialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    1,   58,    2, 0x08,    3 /* Private */,
       5,    1,   61,    2, 0x08,    5 /* Private */,
       7,    0,   64,    2, 0x08,    7 /* Private */,
       8,    0,   65,    2, 0x08,    8 /* Private */,
       9,    0,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject new_data_dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSnew_data_dialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSnew_data_dialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSnew_data_dialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<new_data_dialog, std::true_type>,
        // method 'on_new_data_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_new_data_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_language_switch_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'receive_table_name'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'init_table'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_new_data_delete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_new_data_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void new_data_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<new_data_dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_new_data_save_clicked(); break;
        case 1: _t->on_new_data_cancel_clicked(); break;
        case 2: _t->on_language_switch_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->receive_table_name((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->init_table(); break;
        case 5: _t->on_new_data_delete_clicked(); break;
        case 6: _t->on_new_data_clear_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *new_data_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *new_data_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSnew_data_dialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int new_data_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
