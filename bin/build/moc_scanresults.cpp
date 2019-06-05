/****************************************************************************
** Meta object code from reading C++ file 'scanresults.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/scanresults.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanresults.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScanResults_t {
    QByteArrayData data[12];
    char stringdata[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanResults_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanResults_t qt_meta_stringdata_ScanResults = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ScanResults"
QT_MOC_LITERAL(1, 12, 9), // "setWpaGui"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "WpaGui*"
QT_MOC_LITERAL(4, 31, 7), // "_wpagui"
QT_MOC_LITERAL(5, 39, 13), // "updateResults"
QT_MOC_LITERAL(6, 53, 11), // "scanRequest"
QT_MOC_LITERAL(7, 65, 10), // "getResults"
QT_MOC_LITERAL(8, 76, 11), // "bssSelected"
QT_MOC_LITERAL(9, 88, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(10, 105, 3), // "sel"
QT_MOC_LITERAL(11, 109, 14) // "languageChange"

    },
    "ScanResults\0setWpaGui\0\0WpaGui*\0_wpagui\0"
    "updateResults\0scanRequest\0getResults\0"
    "bssSelected\0QTreeWidgetItem*\0sel\0"
    "languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanResults[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,
       8,    1,   50,    2, 0x0a /* Public */,
      11,    0,   53,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void ScanResults::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScanResults *_t = static_cast<ScanResults *>(_o);
        switch (_id) {
        case 0: _t->setWpaGui((*reinterpret_cast< WpaGui*(*)>(_a[1]))); break;
        case 1: _t->updateResults(); break;
        case 2: _t->scanRequest(); break;
        case 3: _t->getResults(); break;
        case 4: _t->bssSelected((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->languageChange(); break;
        default: ;
        }
    }
}

const QMetaObject ScanResults::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScanResults.data,
      qt_meta_data_ScanResults,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScanResults::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanResults::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScanResults.stringdata))
        return static_cast<void*>(const_cast< ScanResults*>(this));
    if (!strcmp(_clname, "Ui::ScanResults"))
        return static_cast< Ui::ScanResults*>(const_cast< ScanResults*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScanResults::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
