/****************************************************************************
** Meta object code from reading C++ file 'playerlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/mplayer/playerlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlayerList_t {
    QByteArrayData data[9];
    char stringdata[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerList_t qt_meta_stringdata_PlayerList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PlayerList"
QT_MOC_LITERAL(1, 11, 10), // "playmyList"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "index"
QT_MOC_LITERAL(4, 29, 13), // "slotAddButton"
QT_MOC_LITERAL(5, 43, 13), // "slotDelButton"
QT_MOC_LITERAL(6, 57, 16), // "slotDelAllButton"
QT_MOC_LITERAL(7, 74, 10), // "slotSelect"
QT_MOC_LITERAL(8, 85, 20) // "slotloopAroundButton"

    },
    "PlayerList\0playmyList\0\0index\0slotAddButton\0"
    "slotDelButton\0slotDelAllButton\0"
    "slotSelect\0slotloopAroundButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,

       0        // eod
};

void PlayerList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerList *_t = static_cast<PlayerList *>(_o);
        switch (_id) {
        case 0: _t->playmyList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotAddButton(); break;
        case 2: _t->slotDelButton(); break;
        case 3: _t->slotDelAllButton(); break;
        case 4: _t->slotSelect((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->slotloopAroundButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlayerList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerList::playmyList)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PlayerList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerList.data,
      qt_meta_data_PlayerList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlayerList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerList.stringdata))
        return static_cast<void*>(const_cast< PlayerList*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayerList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void PlayerList::playmyList(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
