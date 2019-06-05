/****************************************************************************
** Meta object code from reading C++ file 'IVFDTcpServerHB.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDTcpServerHB.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDTcpServerHB.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDTcpServerHB_t {
    QByteArrayData data[13];
    char stringdata[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDTcpServerHB_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDTcpServerHB_t qt_meta_stringdata_IVFDTcpServerHB = {
    {
QT_MOC_LITERAL(0, 0, 15), // "IVFDTcpServerHB"
QT_MOC_LITERAL(1, 16, 13), // "SIG_NewClient"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 2), // "id"
QT_MOC_LITERAL(4, 34, 12), // "SIG_SendData"
QT_MOC_LITERAL(5, 47, 4), // "data"
QT_MOC_LITERAL(6, 52, 20), // "SIG_DisconnectClient"
QT_MOC_LITERAL(7, 73, 21), // "SLOT_CheckClientTimer"
QT_MOC_LITERAL(8, 95, 22), // "SLOT_ClientHeartStatus"
QT_MOC_LITERAL(9, 118, 14), // "nHeartOutTimes"
QT_MOC_LITERAL(10, 133, 21), // "SLOT_ClientDisconnect"
QT_MOC_LITERAL(11, 155, 15), // "SLOT_RecMessage"
QT_MOC_LITERAL(12, 171, 5) // "cmdID"

    },
    "IVFDTcpServerHB\0SIG_NewClient\0\0id\0"
    "SIG_SendData\0data\0SIG_DisconnectClient\0"
    "SLOT_CheckClientTimer\0SLOT_ClientHeartStatus\0"
    "nHeartOutTimes\0SLOT_ClientDisconnect\0"
    "SLOT_RecMessage\0cmdID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDTcpServerHB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       6,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   60,    2, 0x08 /* Private */,
       8,    2,   61,    2, 0x08 /* Private */,
      10,    1,   66,    2, 0x08 /* Private */,
      11,    3,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,   12,    5,

       0        // eod
};

void IVFDTcpServerHB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDTcpServerHB *_t = static_cast<IVFDTcpServerHB *>(_o);
        switch (_id) {
        case 0: _t->SIG_NewClient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SIG_SendData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->SIG_DisconnectClient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SLOT_CheckClientTimer(); break;
        case 4: _t->SLOT_ClientHeartStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->SLOT_ClientDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SLOT_RecMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDTcpServerHB::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerHB::SIG_NewClient)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDTcpServerHB::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerHB::SIG_SendData)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDTcpServerHB::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerHB::SIG_DisconnectClient)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject IVFDTcpServerHB::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_IVFDTcpServerHB.data,
      qt_meta_data_IVFDTcpServerHB,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDTcpServerHB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDTcpServerHB::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDTcpServerHB.stringdata))
        return static_cast<void*>(const_cast< IVFDTcpServerHB*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int IVFDTcpServerHB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void IVFDTcpServerHB::SIG_NewClient(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IVFDTcpServerHB::SIG_SendData(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IVFDTcpServerHB::SIG_DisconnectClient(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
