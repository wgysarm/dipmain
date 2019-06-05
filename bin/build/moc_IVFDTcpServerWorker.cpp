/****************************************************************************
** Meta object code from reading C++ file 'IVFDTcpServerWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/IVFDTcpServerWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDTcpServerWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDTcpServerWorker_t {
    QByteArrayData data[16];
    char stringdata[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDTcpServerWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDTcpServerWorker_t qt_meta_stringdata_IVFDTcpServerWorker = {
    {
QT_MOC_LITERAL(0, 0, 19), // "IVFDTcpServerWorker"
QT_MOC_LITERAL(1, 20, 22), // "SIG_SendData2TcpSocket"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "data"
QT_MOC_LITERAL(4, 49, 2), // "id"
QT_MOC_LITERAL(5, 52, 23), // "SIG_DisConnectTcpSocket"
QT_MOC_LITERAL(6, 76, 20), // "SIG_ClientDisconnect"
QT_MOC_LITERAL(7, 97, 21), // "SIG_ClientHeartStatus"
QT_MOC_LITERAL(8, 119, 14), // "nHeartOutTimes"
QT_MOC_LITERAL(9, 134, 14), // "SIG_RevMessage"
QT_MOC_LITERAL(10, 149, 5), // "cmdID"
QT_MOC_LITERAL(11, 155, 25), // "SLOT_RevMessageFromClient"
QT_MOC_LITERAL(12, 181, 21), // "SLOT_ClientDisConnect"
QT_MOC_LITERAL(13, 203, 14), // "SLOT_NewClient"
QT_MOC_LITERAL(14, 218, 13), // "SLOT_SendData"
QT_MOC_LITERAL(15, 232, 21) // "SLOT_DisConnectClient"

    },
    "IVFDTcpServerWorker\0SIG_SendData2TcpSocket\0"
    "\0data\0id\0SIG_DisConnectTcpSocket\0"
    "SIG_ClientDisconnect\0SIG_ClientHeartStatus\0"
    "nHeartOutTimes\0SIG_RevMessage\0cmdID\0"
    "SLOT_RevMessageFromClient\0"
    "SLOT_ClientDisConnect\0SLOT_NewClient\0"
    "SLOT_SendData\0SLOT_DisConnectClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDTcpServerWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       6,    1,   72,    2, 0x06 /* Public */,
       7,    2,   75,    2, 0x06 /* Public */,
       9,    3,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   87,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    1,   89,    2, 0x0a /* Public */,
      14,    2,   92,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    4,   10,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,    3,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void IVFDTcpServerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDTcpServerWorker *_t = static_cast<IVFDTcpServerWorker *>(_o);
        switch (_id) {
        case 0: _t->SIG_SendData2TcpSocket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SIG_DisConnectTcpSocket((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SIG_ClientDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SIG_ClientHeartStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->SIG_RevMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->SLOT_RevMessageFromClient(); break;
        case 6: _t->SLOT_ClientDisConnect(); break;
        case 7: _t->SLOT_NewClient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SLOT_SendData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->SLOT_DisConnectClient((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDTcpServerWorker::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerWorker::SIG_SendData2TcpSocket)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDTcpServerWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerWorker::SIG_DisConnectTcpSocket)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDTcpServerWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerWorker::SIG_ClientDisconnect)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDTcpServerWorker::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerWorker::SIG_ClientHeartStatus)) {
                *result = 3;
            }
        }
        {
            typedef void (IVFDTcpServerWorker::*_t)(int , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDTcpServerWorker::SIG_RevMessage)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject IVFDTcpServerWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDTcpServerWorker.data,
      qt_meta_data_IVFDTcpServerWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDTcpServerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDTcpServerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDTcpServerWorker.stringdata))
        return static_cast<void*>(const_cast< IVFDTcpServerWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDTcpServerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void IVFDTcpServerWorker::SIG_SendData2TcpSocket(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IVFDTcpServerWorker::SIG_DisConnectTcpSocket(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IVFDTcpServerWorker::SIG_ClientDisconnect(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IVFDTcpServerWorker::SIG_ClientHeartStatus(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IVFDTcpServerWorker::SIG_RevMessage(int _t1, int _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
