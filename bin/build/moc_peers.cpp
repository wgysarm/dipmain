/****************************************************************************
** Meta object code from reading C++ file 'peers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/peers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'peers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Peers_t {
    QByteArrayData data[13];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Peers_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Peers_t qt_meta_stringdata_Peers = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Peers"
QT_MOC_LITERAL(1, 6, 12), // "context_menu"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "pos"
QT_MOC_LITERAL(4, 24, 9), // "enter_pin"
QT_MOC_LITERAL(5, 34, 11), // "connect_pbc"
QT_MOC_LITERAL(6, 46, 15), // "learn_ap_config"
QT_MOC_LITERAL(7, 62, 11), // "ctx_refresh"
QT_MOC_LITERAL(8, 74, 10), // "properties"
QT_MOC_LITERAL(9, 85, 14), // "languageChange"
QT_MOC_LITERAL(10, 100, 10), // "closeEvent"
QT_MOC_LITERAL(11, 111, 12), // "QCloseEvent*"
QT_MOC_LITERAL(12, 124, 5) // "event"

    },
    "Peers\0context_menu\0\0pos\0enter_pin\0"
    "connect_pbc\0learn_ap_config\0ctx_refresh\0"
    "properties\0languageChange\0closeEvent\0"
    "QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Peers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x09 /* Protected */,
      10,    1,   63,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void Peers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Peers *_t = static_cast<Peers *>(_o);
        switch (_id) {
        case 0: _t->context_menu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->enter_pin(); break;
        case 2: _t->connect_pbc(); break;
        case 3: _t->learn_ap_config(); break;
        case 4: _t->ctx_refresh(); break;
        case 5: _t->properties(); break;
        case 6: _t->languageChange(); break;
        case 7: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Peers::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Peers.data,
      qt_meta_data_Peers,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Peers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Peers::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Peers.stringdata))
        return static_cast<void*>(const_cast< Peers*>(this));
    if (!strcmp(_clname, "Ui::Peers"))
        return static_cast< Ui::Peers*>(const_cast< Peers*>(this));
    return QDialog::qt_metacast(_clname);
}

int Peers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
