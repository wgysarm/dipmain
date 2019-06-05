/****************************************************************************
** Meta object code from reading C++ file 'networkconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/networkconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkConfig_t {
    QByteArrayData data[16];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkConfig_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkConfig_t qt_meta_stringdata_NetworkConfig = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NetworkConfig"
QT_MOC_LITERAL(1, 14, 11), // "authChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "sel"
QT_MOC_LITERAL(4, 31, 10), // "addNetwork"
QT_MOC_LITERAL(5, 42, 11), // "encrChanged"
QT_MOC_LITERAL(6, 54, 11), // "writeWepKey"
QT_MOC_LITERAL(7, 66, 10), // "network_id"
QT_MOC_LITERAL(8, 77, 10), // "QLineEdit*"
QT_MOC_LITERAL(9, 88, 4), // "edit"
QT_MOC_LITERAL(10, 93, 2), // "id"
QT_MOC_LITERAL(11, 96, 13), // "removeNetwork"
QT_MOC_LITERAL(12, 110, 10), // "eapChanged"
QT_MOC_LITERAL(13, 121, 6), // "useWps"
QT_MOC_LITERAL(14, 128, 14), // "languageChange"
QT_MOC_LITERAL(15, 143, 22) // "on_addButton_2_clicked"

    },
    "NetworkConfig\0authChanged\0\0sel\0"
    "addNetwork\0encrChanged\0writeWepKey\0"
    "network_id\0QLineEdit*\0edit\0id\0"
    "removeNetwork\0eapChanged\0useWps\0"
    "languageChange\0on_addButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    0,   62,    2, 0x0a /* Public */,
       5,    1,   63,    2, 0x0a /* Public */,
       6,    3,   66,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x0a /* Public */,
      13,    0,   77,    2, 0x0a /* Public */,
      14,    0,   78,    2, 0x09 /* Protected */,
      15,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8, QMetaType::Int,    7,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NetworkConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkConfig *_t = static_cast<NetworkConfig *>(_o);
        switch (_id) {
        case 0: _t->authChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addNetwork(); break;
        case 2: _t->encrChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->writeWepKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->removeNetwork(); break;
        case 5: _t->eapChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->useWps(); break;
        case 7: _t->languageChange(); break;
        case 8: _t->on_addButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject NetworkConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NetworkConfig.data,
      qt_meta_data_NetworkConfig,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetworkConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkConfig.stringdata))
        return static_cast<void*>(const_cast< NetworkConfig*>(this));
    if (!strcmp(_clname, "Ui::NetworkConfig"))
        return static_cast< Ui::NetworkConfig*>(const_cast< NetworkConfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int NetworkConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
